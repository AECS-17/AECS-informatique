/* Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE.BSD file. */

#include <gst/gst.h>

/*
 *  Structure of the pipeline element:
 *
 *                   URI                   \
 *                    |                     |
 *             flux multimedia              |
 *                    |                     |
 *      ______________V____________         |
 *     |                           |        |
 *     |           decoder         |        |
 *     |        (uridecodebin)     |        |
 *     |___________________________|        |
 *         |                  |             | Handled by run-pipeline.c
 *         |                  |             |
 *     audio/x-raw        video/x-raw       |
 *         |                  |             |
 *  _______V________   _______V________     |
 * |                | |                |    |
 * |  audio_source  | |  video_source  |    |
 * | (audioconvert) | | (videoconvert) |    |
 * |________________| |________________|    |
 *         |                  |             |
 *         V                  V            /
 *
 *                                         \
 *                                          |
 *        OTHER GSTREAMER ELEMENTS          | Handled by pipeline.c
 *                                          |
 *                                         /
 */

/* Data structure for the pipeline, passed between functions. */
typedef struct _PipelineData {

  /* Glib main loop event, to wait for keyboard events */
  GMainLoop* loop;

  /* Pointers to the pipeline and audio & video elements (see above) */
  GstElement* pipeline;
  GstElement* audio_source;
  GstElement* video_source;

  /* Extra elements and parameters handled by pipeline.c */
  GstElement* volume_element;
  gboolean volume_mute;

} PipelineData;

/* This function creates the elements at the end of the pipeline (see
 * "OTHER GSTREAMER ELEMENTS" above) and do all the necessary connections. It
 * is assumed that data->pipeline, data->audio_source, data->video_source
 * elements are properly set when this function is called.
 * It returns TRUE if the operation is successful and FALSE if an error occurs.
 */
gboolean setup_pipeline(PipelineData* data);

/* This function prints the keyboard commands and instructions supported by
 * handle_keyboard_command().
 */
void print_keyboard_commands();

/* This function handles the key entered by the user. It is assumed that all the
 * members of the PipelineData are properly set when this function is called.
 * It can use the data and modify the elements, connections or properties.
 */
void handle_keyboard_command(PipelineData* data, char key);
