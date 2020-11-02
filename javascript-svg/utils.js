// Copyright 2020 Frédéric Wang. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

module.exports = {
    header: function(width, height, title, description, author) {
        return `<?xml version="1.0" encoding="UTF-8"?>
<!-- This file was automatically generated. Do not edit! -->
<svg xmlns:dc="http://purl.org/dc/elements/1.1/"
     xmlns:cc="http://creativecommons.org/ns#"
     xmlns:xlink="http://www.w3.org/1999/xlink"
     xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#"
     xmlns="http://www.w3.org/2000/svg"
     width="${width}px"
     height="${height}px">
  <metadata>
    <rdf:RDF>
      <cc:Work
         rdf:about="">
        <dc:format>image/svg+xml</dc:format>
        <dc:type
           rdf:resource="http://purl.org/dc/dcmitype/StillImage" />
        <dc:title>${title}</dc:title>
        <cc:license
           rdf:resource="http://creativecommons.org/licenses/by/4.0/" />
        <dc:creator>
          <cc:Agent>
            <dc:title>${author}</dc:title>
          </cc:Agent>
        </dc:creator>
      </cc:Work>
      <cc:License
         rdf:about="http://creativecommons.org/licenses/by/4.0/">
        <cc:permits
           rdf:resource="http://creativecommons.org/ns#Reproduction" />
        <cc:permits
           rdf:resource="http://creativecommons.org/ns#Distribution" />
        <cc:requires
           rdf:resource="http://creativecommons.org/ns#Notice" />
        <cc:requires
           rdf:resource="http://creativecommons.org/ns#Attribution" />
        <cc:permits
           rdf:resource="http://creativecommons.org/ns#DerivativeWorks" />
      </cc:License>
    </rdf:RDF>
  </metadata>
  <title>${title}</title>
  <desc>${description}</desc>
  <rect width="${width}" height="${height}" style="fill: black"/>
`;
    },
    footer: "</svg>",
    circle: function(cx, cy, r, color) {
        return `<circle cx="${cx}" cy="${cy}" r="${r}" style="fill: ${color}"/>`;
    },
    line: function(x1, y1, x2, y2, color) {
        throw "This function is not implemented!";
    },
    random_integer: function(min, max) {
        return Math.floor(Math.random() * (max - min + 1) + min);
    },
}
