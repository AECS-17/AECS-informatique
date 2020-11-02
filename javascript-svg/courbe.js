// Copyright 2020 Frédéric Wang. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

const fs = require("fs");
const utils = require('./utils');

let stream = fs.createWriteStream("courbe.svg");

const width = 600;
const height = 200;

function f(x) {
    return (1 + Math.sin(4 * x * Math.PI / width)) * (height / 2) +
        ((x**2) % 10 - 5);
}

stream.write(utils.header(
    width,
    height,
    "Courbe",
    "Tracé de la fonction f",
    "Frédéric Wang"
));

for (let x = 0; x < width; x++) {
    stream.write(utils.line(x, f(x), x+1, f(x+1), "white"));
}

stream.write(utils.footer);

stream.end();
