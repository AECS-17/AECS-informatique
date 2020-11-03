/* Use of this source code is governed by a BSD-style license that can be
   found in the LICENSE.BSD file. */

#include "pipeline.h"
#include <gst/gst.h>
#include <libgen.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

/* Default video URI */
const char* default_uri = "https://www.freedesktop.org/software/gstreamer-sdk/data/media/sintel_trailer-480p.webm";

/* Process keyboard input */
static gboolean
handle_keyboard(GIOChannel* source, GIOCondition cond, PipelineData* data)
{
  gchar *str = NULL;
  if (g_io_channel_read_line (source, &str, NULL, NULL,
          NULL) != G_IO_STATUS_NORMAL) {
    return TRUE;
  }
  handle_keyboard_command(data, g_ascii_toupper(str[0]));
  g_free(str);
  return TRUE;
}

/* Handler for the pad-added signal */
static void pad_added_handler(GstElement *src, GstPad *new_pad,
                              PipelineData *data) {
  GstCaps* new_pad_caps = gst_pad_get_current_caps (new_pad);
  guint new_pad_caps_size = gst_caps_get_size (new_pad_caps);
  for (guint i = 0; i < new_pad_caps_size; i++) {
    /* Verify the pad type */
    GstStructure * new_pad_struct = gst_caps_get_structure (new_pad_caps, i);
    const gchar *new_pad_type = gst_structure_get_name (new_pad_struct);
    GstPad *sink_pad;
    if (g_str_has_prefix (new_pad_type, "video/x-raw")) {
      sink_pad = gst_element_get_static_pad (data->video_source, "sink");
    } else if (g_str_has_prefix (new_pad_type, "audio/x-raw")) {
      sink_pad = gst_element_get_static_pad (data->audio_source, "sink");
    } else {
      continue;
    }

    /* If our converter is already linked, we have nothing to do here */
    if (gst_pad_is_linked (sink_pad)) {
      gst_object_unref (sink_pad);
      continue;
    }

    /* Attempt the link */
    GstPadLinkReturn ret = gst_pad_link (new_pad, sink_pad);
    gst_object_unref (sink_pad);
  }

  /* Unreference the new pad's caps, if we got them */
  if (new_pad_caps)
    gst_caps_unref (new_pad_caps);
}

int main(int argc, char *argv[])
{
  /* Allow to support French characters */
  setlocale(LC_CTYPE, "");

  /* Initialize GStreamer */
  gst_init (&argc, &argv);

  /* Parse command line argument */
  if (argc != 1 && argc != 2) {
    g_printerr ("Usage: %s [URI]\n", basename(argv[0]));
    return -1;
  }
  const char* video_uri = argc == 2 ? argv[1] : default_uri;

  /* Create the pipeline */
  PipelineData data;
  data.pipeline = gst_pipeline_new ("my-pipeline");
  GstElement* decoder = gst_element_factory_make ("uridecodebin", "decoder");
  data.audio_source =
    gst_element_factory_make ("audioconvert", "audioconvert");
  data.video_source =
    gst_element_factory_make ("videoconvert", "videoconvert");
  gst_bin_add_many (GST_BIN (data.pipeline), decoder,
                    data.audio_source, data.video_source, NULL);
  if (!data.pipeline || !decoder || !data.audio_source || !data.video_source ||
      !setup_pipeline(&data)) {
    g_printerr ("Unable to create the pipeline\n");
    if (data.pipeline)
      gst_object_unref (data.pipeline);
    return -1;
  }

   /* Set the URI to play */
  g_object_set (decoder, "uri", video_uri, NULL);

  /* Connect to the pad-added signal */
  g_signal_connect (decoder, "pad-added",
                    G_CALLBACK (pad_added_handler), &data);

  /* Add a keyboard watch so we get notified of keystrokes */
  GIOChannel *io_stdin = g_io_channel_unix_new (fileno (stdin));
  g_io_add_watch (io_stdin, G_IO_IN, (GIOFunc) handle_keyboard, &data);

  /* Start playing */
  GstStateChangeReturn ret =
    gst_element_set_state (data.pipeline, GST_STATE_PLAYING);
  if (ret == GST_STATE_CHANGE_FAILURE) {
    g_printerr ("Unable to set the pipeline to the playing state.\n");
    gst_object_unref (data.pipeline);
    return -1;
  }

  /* Create a GLib Main Loop and set it to run */
  print_keyboard_commands();
  data.loop = g_main_loop_new (NULL, FALSE);
  g_main_loop_run (data.loop);
  g_main_loop_unref (data.loop);
  g_io_channel_unref (io_stdin);

  /* Free resources */
  gst_element_set_state (data.pipeline, GST_STATE_NULL);
  gst_object_unref (data.pipeline);
  return 0;
}
