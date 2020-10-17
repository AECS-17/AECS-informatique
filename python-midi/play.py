# Copyright 2020 Frédéric Wang
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice,
# this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright notice,
# this list of conditions and the following disclaimer in the documentation
# and/or other materials provided with the distribution.
#
# 3. Neither the name of the copyright holder nor the names of its contributors
# may be used to endorse or promote products derived from this software without
# specific prior written permission.

# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
# OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

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
