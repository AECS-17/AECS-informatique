# Programmation Python et musique MIDI

Dans cette session, nous verrons un aperçu de concepts de programmation à l’aide du langage [Python](https://fr.wikipedia.org/wiki/Python_(langage)), utilisé notamment pour l’automatisation de tâches. Nous prendrons pour exemple une bibliothèque de manipulation de musique au [format MIDI](https://fr.wikipedia.org/wiki/Musical_Instrument_Digital_Interface) afin d’étudier et de modifier de petits programmes interactifs utilisant un clavier de piano, des fichiers musicaux et la sortie audio.

![Capture d’écran](https://raw.githubusercontent.com/AECS-17/AECS-informatique/master/python-midi/capture.png)

## Objectifs pédagogiques

* Clavier virtuel, connection MIDI, synthétiseur.
* Éditeur de partition musicale.
* Bases du langage Python
* Variables, fonctions, boucles, interfaces entrée/sortie.
* Structure de graphe.
* Bibliothèque [python-mito](https://mido.readthedocs.io/en/latest/).

## Déroulement possible de la session

0. Introduction.
1. Mettre en place des connections MIDI (clavier virtuel/physique, qjackctl, qsynth) et vérifier que l'on peut jouer au clavier.
2. Étudier et exécuter [ports.py](https://github.com/AECS-17/AECS-informatique/blob/master/python-midi/ports.py): Afficher les ports MIDI disponibles et comparer avec qjackctl.
3. Étudier et exécuter [listen.py](https://github.com/AECS-17/AECS-informatique/blob/master/python-midi/listen.py). Connecter une entrée MIDI et vérifier les messages reçus.
4. Étudier et exécuter [play.py](https://github.com/AECS-17/AECS-informatique/blob/master/python-midi/play.py). Connecter une sortie MIDI pour jouer les notes entrées par l’utilisateur.
5. Utilisez [MuseScore](https://fr.wikipedia.org/wiki/MuseScore) pour créer un fichier MIDI (e.g. à partir de `A-E-C-Si.musicxml`).
6. Étudier et exécuter [read-and-play.py](https://github.com/AECS-17/AECS-informatique/blob/master/python-midi/read-and-play.py). Faire en sorte qu'il lise et joue la musique.
7. Selon le temps disponible, écrire ses propres mini-programmes intéragissant entre l’entrée au clavier MIDI, les fichiers MIDI ou la sortie audio.

## Installation

L’environnement suivant sera mis à disposition pour cette session:

* Un clavier MIDI
* Linux Mint >= 20
* Paquets `qjackctl alsaplayer-jack vmpk qsynth musescore`. Accepter l'activation du [temps réel](https://fr.wikipedia.org/wiki/Syst%C3%A8me_d'exploitation_temps_r%C3%A9el) (fichier `/etc/security/limits.d/audio.conf` présent) et ajouter l'utilisateur au groupe `audio`).
* Paquets `python3 python3-mido python3-rtmidi librtmidi5`
