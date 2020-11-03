/* Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE.BSD file. */

#include <gst/gst.h>
#include "pipeline.h"

/* Helper function to create an element with gst_element_factory_make, add it
 * to the pipeline and return it. If it fails, it returns NULL and prints a
 * message error.
 */
GstElement* add_element_to_pipeline(GstElement* pipeline,
                                    const gchar * factoryname,
                                    const gchar * name)
{
  GstElement* element = gst_element_factory_make (factoryname, name);
  if (!element) {
    g_printerr ("Unable to create element '%s'\n", name);
  } else {
    gst_bin_add (GST_BIN (pipeline), element);
  }
  return element;
}

gboolean setup_pipeline(PipelineData* data)
{
  /* Create the volume element */
  data->volume_element =
    add_element_to_pipeline(data->pipeline, "volume", "volume1");
  if (!data->volume_element)
    return FALSE;
  data->volume_mute = TRUE;
  g_object_set(data->volume_element, "mute", data->volume_mute, NULL);

  /* Create the audioresample element */
  GstElement* audioresample =
    add_element_to_pipeline(data->pipeline, "audioresample", "audioresample1");
  if (!audioresample)
    return FALSE;

  /* Create the autoaudiosink element */
  GstElement* autoaudiosink =
    add_element_to_pipeline(data->pipeline, "autoaudiosink", "autoaudiosink1");
  if (!autoaudiosink)
    return FALSE;

  /* Link audio elements */
  if (gst_element_link_many (data->audio_source,
                             data->volume_element, audioresample,
                             autoaudiosink, NULL) != TRUE) {
    g_printerr ("Unable to link audio elements\n");
    return FALSE;
  }

  /* Create the videoconvert element */
  GstElement* videoconvert =
    add_element_to_pipeline(data->pipeline, "videoconvert", "videoconvert1");
  if (!videoconvert)
    return FALSE;

  /* Create the autovideosink element */
  GstElement* autovideosink =
    add_element_to_pipeline(data->pipeline, "autovideosink", "autovideosink1");
  if (!autovideosink)
    return FALSE;

  /* Link video elements */
  if (gst_element_link_many (data->video_source, videoconvert,
                             autovideosink, NULL) != TRUE) {
    g_printerr ("Unable to video elements\n");
    return FALSE;
  }

  return TRUE;
}

void print_keyboard_commands()
{
  g_print ("Choisissez une des options suivantes et validez avec Entrée:\n"
           "'Q' pour quitter\n"
           "'S' pour activer/désactiver le son\n"
           );
}

void handle_keyboard_command(PipelineData* data, char key)
{
  switch (key) {
  case 'Q':
    g_main_loop_quit (data->loop);
    break;
  case 'S':
    data->volume_mute = !data->volume_mute;
    g_object_set(data->volume_element, "mute", data->volume_mute, NULL);
    break;
  default:
    g_print ("Commande non reconnue !\n");
    print_keyboard_commands();
    break;
  }
}
