// Copyright 2020 Frédéric Wang. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

const fs = require("fs");
const utils = require('./utils');

let stream = fs.createWriteStream("aleatoire.svg");

const width = 500;
const height = 400;
const number = 100;

stream.write(utils.header(
    width,
    height,
    "Nuage",
    "Plusieurs disques de couleurs et positions différentes",
    "Frédéric Wang"
));

for (let i = 0; i < number; i++) {
    let x = utils.random_integer(0, width);
    let y = utils.random_integer(0, height);
    let red = utils.random_integer(100, 200);
    let green = utils.random_integer(100, 200);
    let blue = utils.random_integer(100, 200);
    stream.write(utils.circle(x, y, 10, `rgb(${red}, ${green}, ${blue})`));
}

stream.write(utils.footer);

stream.end();
