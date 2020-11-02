// Copyright 2020 Frédéric Wang. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

const fs = require("fs");
const utils = require('./utils');

let stream = fs.createWriteStream("concentriques.svg");

stream.write(utils.header(
    500,
    500,
    "Ma cible",
    "Des disques concentriques de différentes couleurs",
    "Frédéric Wang"
));

for (let i = 0; i < 10; i++) {
    stream.write(utils.circle(250, 250, 250 - 25 * i,
                              `rgb(${25 * i}, 0, ${250 - 25 * i})`));
}

stream.write(utils.footer);

stream.end();
