# Programmation Java et application mobile

Dans cette session, nous verrons un aperçu de concepts de programmation à l’aide du langage [Java](https://fr.wikipedia.org/wiki/Java_(technique)). Nous créerons une mini application mobile pour [Android](https://en.wikipedia.org/wiki/Android_(operating_system)).

![Capture d’écran](https://raw.githubusercontent.com/AECS-17/AECS-informatique/master/java-application-mobile/capture.png)

## Objectifs pédagogiques

* Syntaxe de base Java
* Application android, interface graphique, activité
* Anbox, adb

## Déroulement possible de la session

0. Introduction.
1. Build [hello world](https://gitlab.com/Matrixcoffee/hello-world-debian-android/) app, install and run it in Anbox
2. Modify it to add new graphical element, actions, etc

À faire: trouver plus idées à partir de [la documentation Android](https://developer.android.com/docs/)...

## Installation

L’environnement suivant sera mis à disposition pour cette session:

* Linux Mint >= 20
* Paquets `make android-sdk android-sdk-platform-23`
* [Anbox](https://anbox.io/): paquets `anbox`, module du noyau `ashmem` et `binder` activé, [image Android](https://build.anbox.io/android-images/) installée. Voir les [instructions de Debian](https://salsa.debian.org/zhsj/anbox/blob/master/debian/README.Debian).
