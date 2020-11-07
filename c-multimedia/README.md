# Programmation C et flux multimedia

Dans cette session, nous verrons un aperçu de concepts de programmation à l’aide du langage [C](https://fr.wikipedia.org/wiki/C_(langage)) qui est (avec ses variantes [C++](https://fr.wikipedia.org/wiki/C%2B%2B), [Objective C](https://fr.wikipedia.org/wiki/Objective-C), [C#](https://fr.wikipedia.org/wiki/C_sharp)) très utilisé dans l'industrie. Nous prendrons pour exemple une [bibliothèque de manipulation de sons et d'images](https://fr.wikipedia.org/wiki/GStreamer) afin d’étudier et de modifier des petites fonctions d'un module utilisé par un mini-lecteur multimedia.

![Capture d’écran](https://raw.githubusercontent.com/AECS-17/AECS-informatique/master/c-multimedia/capture.png)

## Objectifs pédagogiques

* Syntaxe de base C: fonction, variable, condition, structure, switch, etc
* Compilation d’un programme.
* Execution de programme avec arguments.
* Structure de graphe.
* Édition d’une mini-bibliothèque C
* Bibliothèque [GStreamer](https://fr.wikipedia.org/wiki/GStreamer).

## Déroulement possible de la session

0. Introduction.
1. Compilation avec `make` et execution du programme avec `./run-pipeline`.
2. Télécharger `https://interactive-examples.mdn.mozilla.net/media/cc0-videos/flower.webm` et passer le fichier comme argument de `./run-pipeline`.
3. Étudier [pipeline.h](https://github.com/AECS-17/AECS-informatique/blob/master/c-multimedia/pipeline.h) et [pipeline.c](https://github.com/AECS-17/AECS-informatique/blob/master/c-multimedia/pipeline.c)
4. Modifier `print_keyboard_commands()` pour afficher un message différent.
5. Ajouter une commande 'P' dans `handle_keyboard_command()` qui affiche si
   le son est allumé ou éteint.
6. Ajouter des commandes '+' et '-' pour augmenter ou diminuer le
   [volume](https://gstreamer.freedesktop.org/documentation/volume/index.html?gi-language=c#volume:volume)
6. Ajouter des filtres vidéo dans `setup_pipeline()`, par exemple
   [mirror](https://gstreamer.freedesktop.org/documentation/geometrictransform/mirror.html?gi-language=c),
   [ASCII art](https://gstreamer.freedesktop.org/documentation/aasink/aatv.html?gi-language=c#aatv),
   [rotate](https://gstreamer.freedesktop.org/documentation/geometrictransform/rotate.html?gi-language=c#rotate), etc
8. Selon le temps disponible, ajouter plus de filtres et de commandes.

## Installation

L’environnement suivant sera mis à disposition pour cette session:

* Linux Mint >= 20
* Paquets `make gcc libgstreamer1.0-dev`
