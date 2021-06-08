# Programmation Assembleur et algorithme d'Euclide

Dans cette session, nous verrons comment utiliser le langage [WebAssembly](https://webassembly.org/) pour implémenter l'algorithme d'Euclide et des programmes simples. Un [langage assembleur](https://fr.wikipedia.org/wiki/Assembleur) est langage de plus bas niveau qui représente le langage machine sous une forme lisible par un humain. Bien que [l'intérêt d'écrire directement de l'assembleur est sujet à débat](https://fr.wikipedia.org/wiki/Assembleur#Usage_du_langage_assembleur), il reste intéressant pour comprendre comment son exécutés les programmes compilés.

## Objectifs pédagogiques

* Concept de piles.
* Syntaxe de base WebAssembly : fonctions, operations, condition, boucle.

## Déroulement possible de la session

0. Introduction.
1. Étudier le programme [binary-operator.wat](https://github.com/AECS-17/AECS-informatique/blob/master/wasm-euclidean/binary-operator.wat)
2. Générer un fichier binaire `binary-operator.wasm` en utilisant la commande `wat2wasm binary-operator.wat`
3. Utiliser [run.js](https://github.com/AECS-17/AECS-informatique/blob/master/wasm-euclidean/run.js) pour charger et exécuter `binary-operator.wasm` avec la commande `nodejs run.js binary-operator.wasm 5 7` pour calculer 5 + 7.
4. Essayer avec d'autres arguments et d'autres operateurs binaires e.g. `i32.sub` (addition), `i32.mul` (multiplication), `i32.div_s` (division euclidienne), `i32.rem_s` (reste de la division euclidienne).
5. Désassembler le programme avec la commande `wasm2wat binary-operator.wasm` et comparer le résultat avec `binary-operator.wat`.
6. Étudier le programme [conditional.wat](https://github.com/AECS-17/AECS-informatique/blob/master/wasm-euclidean/conditional.wat), générer le fichier binaire `conditional.wasm` et exécuter-le à l'aide de `run.js`. Quelle est la fonction implémentée par ce programme ?
7. Faire de même avec [recursive-gcd.wat](https://github.com/AECS-17/AECS-informatique/blob/master/wasm-euclidean/recursive-gcd.wat). Comparer avec [l'algorithme d'euclide récursif](https://fr.wikipedia.org/wiki/Algorithme_d%27Euclide#Version_r%C3%A9cursive).
8. Faire de même avec [iterative-gcd.wat](https://github.com/AECS-17/AECS-informatique/blob/master/wasm-euclidean/iterative-gcd.wat). Comparer avec [l'algorithme d'euclide itératif](https://fr.wikipedia.org/wiki/Algorithme_d%27Euclide#Version_it%C3%A9rative).

## Installation

L’environnement suivant sera mis à disposition pour cette session:

* Linux Mint >= 21
* Paquets `wabt` * `nodejs`
