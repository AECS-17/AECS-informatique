# Copyright 2020 Frédéric Wang. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

import mido

# Create an input port and print MIDI messages received.
print("J'écoute les messages...")
with mido.open_input() as input_port:
      for message in input_port:
          print("J'ai reçu ce message:", message)
