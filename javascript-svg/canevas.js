// Copyright 2020 Frédéric Wang. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

const fs = require("fs");
const utils = require('./utils');

let stream = fs.createWriteStream("canevas.svg");

stream.write(utils.header(
    400,
    200,
    "Mon beau canevas",
    "Un disque bleu",
    "Frédéric Wang"
));

stream.write(utils.circle(200, 100, 50, "blue"));

stream.write(utils.footer);

stream.end();
