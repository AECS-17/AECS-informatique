# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE.BSD file.

run-pipeline: pipeline.c run-pipeline.c
	gcc $^ -o $@ `pkg-config --cflags --libs gstreamer-1.0`

clean:
	rm -f run-pipeline
