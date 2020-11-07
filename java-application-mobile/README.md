# Programmation Java et application mobile

Dans cette session, nous verrons un aperçu de concepts de programmation à l’aide du langage [Java](https://fr.wikipedia.org/wiki/Java_(technique)). Nous créerons une mini application mobile pour [Android](https://en.wikipedia.org/wiki/Android_(operating_system)).

![Capture d’écran](https://raw.githubusercontent.com/AECS-17/AECS-informatique/master/java-application-mobile/capture.png)

## Objectifs pédagogiques

* Syntaxe de base Java
* Application android, interface graphique, activité
* Anbox, adb

## Déroulement possible de la session

0. Introduction.
1. Compiler `AECS-android-app`, l'installer et l'executer dans Anbox
2. Étudier [src/aecs/source/aecsandroidapp/AECSAndroidApp.java](https://github.com/AECS-17/AECS-informatique/blob/master/java-application-mobile/src/aecs/source/aecsandroidapp/AECSAndroidApp.java). Modifier le pour compter combien de fois le bouton a été cliqué et mettre a jour le texte.
3. Étudier [res/layout/activity_main.xml](https://github.com/AECS-17/AECS-informatique/blob/master/java-application-mobile/res/layout/activity_main.xml) et ajouter d'autres boutons, textes. Ajouter d'autres actions.
4. Selon le temps disponible, plus de widgets, actions etc

🚧 Trouver plus idées à partir de [la documentation Android](https://developer.android.com/docs/)...

## Installation

L’environnement suivant sera mis à disposition pour cette session:

* Linux Mint >= 20
* [AndroidTools](https://wiki.debian.org/AndroidTools) `make adb android-sdk android-sdk-platform-23`.
* [Anbox](https://anbox.io/): paquets `anbox`, modules du noyau `ashmem` et `binder` activés, [image Android](https://build.anbox.io/android-images/) installée. Voir les [instructions de Debian](https://salsa.debian.org/zhsj/anbox/blob/master/debian/README.Debian).
