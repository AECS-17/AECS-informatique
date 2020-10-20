# Copyright 2020 Frédéric Wang. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

import mido

# Print information about MIDI ports.
print()
print("Voici les entrées MIDI:")
for name in mido.get_input_names():
    print("-", name)

print()
print("et les sorties:")
for name in mido.get_output_names():
    print("-", name)
print()
