# Copyright 2020 Frédéric Wang. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

import mido, time

# https://en.wikipedia.org/wiki/Musical_note#12-tone_chromatic_scale
note_names = [
     "do",
     "do#",
     "ré",
     "ré#",
     "mi",
     "fa",
     "fa#",
     "sol",
     "sol#",
     "la",
     "la#",
     "si",
]

# https://en.wikipedia.org/wiki/C_(musical_note)#Middle_C
midi_middle_C = 60

# Create an output port and play notes entered by the user.
output_port = mido.open_output()
while True:
     user_input = ""
     while not user_input in note_names:
          user_input = input("Donnez-moi une note: ").strip().lower()

     print("Écoutez-moi jouer...")
     midi_note = midi_middle_C + note_names.index(user_input)
     output_port.send(mido.Message("note_on", note=midi_note))
     time.sleep(.5)
     output_port.send(mido.Message("note_off", note=midi_note))
