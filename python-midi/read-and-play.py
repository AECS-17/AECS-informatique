# Copyright 2020 Frédéric Wang. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

import mido

# Create an output port and send messages read from the MIDI file.
output_port = mido.open_output()
file_name = "A-E-C-Si.mid"
print("Laissez-moi lire le fichier", file_name)
midi_file = mido.MidiFile(file_name)
for message in midi_file.play():
    print(message)
    output_port.send(message)
