# Programmation C et multimedia

Dans cette session, nous verrons un aperçu de concepts de programmation à l’aide du langage [C](https://fr.wikipedia.org/wiki/C_(langage)) qui est (avec ses variantes [C++](https://fr.wikipedia.org/wiki/C%2B%2B), [Objective C](https://fr.wikipedia.org/wiki/Objective-C), [C#](https://fr.wikipedia.org/wiki/C_sharp)) très utilisé dans l'industrie. Nous prendrons pour exemple une [librairie de manipulation de sons et d'images ](https://fr.wikipedia.org/wiki/GStreamer) afin d’étudier et de modifier des fonctions de gestion des flux audio et vidéo.

![Capture d’écran](https://raw.githubusercontent.com/AECS-17/AECS-informatique/master/c-multimedia/capture.png)

## Objectifs pédagogiques

* Syntax de base C: fonction, variable, structure, switch, etc
* Compilation et execution de programme avec arguments.
* Structure de graphe.
                   
## Plan

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
