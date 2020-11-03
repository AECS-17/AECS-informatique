/* Use of this source code is governed by a BSD-style license that can be
   found in the LICENSE.BSD file. */

#include <gst/gst.h>

typedef struct _PipelineData {
  GMainLoop* loop;

  GstElement* pipeline;
  GstElement* audio_source;
  GstElement* video_source;

  GstElement* volume_element;
  gboolean volume_mute;

} PipelineData;

gboolean setup_pipeline(PipelineData* data);
void print_keyboard_commands();
void handle_keyboard_command(PipelineData* data, char key);
