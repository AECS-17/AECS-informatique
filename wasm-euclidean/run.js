// Copyright 2021 Frédéric Wang. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE.BSD file.

// Parse command line arguments.
if (process.argv.length < 3) {
    console.error(`usage: ${process.argv[0]} ${process.argv[1]} file.wasm parameters`)
    process.exit(1)
}
const wasm = process.argv[2]
parameters = process.argv.slice(3);
console.log("WebAssembly file:", wasm);
console.log("Parameters:", parameters.join(', '))

// Load wasm file and calculate gcd.
const fs = require('fs');
const buffer = fs.readFileSync(wasm);
WebAssembly.instantiate(new Uint8Array(buffer)).then(result => {
    console.log(`Result: ${result.instance.exports.main.apply(null, parameters)}`);
}).catch(error => { console.error(error) });
