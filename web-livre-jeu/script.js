// Copyright 2020 Frédéric Wang. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

function lancer() {
    let resultat = document.getElementById('lander-ballon-resultat');
    resultat.innerHTML = Math.random() < .5 ?
        'Raté ! Tu retournes avec la mine penaude vers tes camarades. <a href="#moqueries">Va en 4</a>.' :
        'En plein dans le mille ! Voilà la pauvre fleur complètement ratatinée ! <a href="#pas-gentil">Va en 13</a>.';
}
