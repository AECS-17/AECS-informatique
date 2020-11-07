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
1. Connection MIDI (clavier virtuel/physique, qjackctl, qsynth)
2. [ports.py](https://github.com/AECS-17/AECS-informatique/blob/master/python-midi/ports.py): Afficher les ports MIDI disponibles.
3. [listen.py](https://github.com/AECS-17/AECS-informatique/blob/master/python-midi/listen.py): Créer une entrée MIDI et afficher les messages MIDI reçu.
4. [play.py](https://github.com/AECS-17/AECS-informatique/blob/master/python-midi/play.py): Créer une sortie MIDI et jouer les notes entrées par l’utilisateur.
5. [read-and-play.py](https://github.com/AECS-17/AECS-informatique/blob/master/python-midi/read-and-play.py): Creer une sortie MIDI et envoyer les messages lus depuis un fichier édité avec [MuseScore](https://fr.wikipedia.org/wiki/MuseScore).
6. Selon le temps disponible, écrire ses propres mini-programmes intéragissant entre l’entrée au clavier MIDI, les fichiers MIDI ou la sortie audio.

## Installation

L’environnement suivant sera mis à disposition pour cette session:

* Un clavier MIDI
* Linux Mint >= 20
* Paquets `qjackctl alsaplayer-jack vmpk qsynth musescore`. Accepter l'activation du [temps réel](https://fr.wikipedia.org/wiki/Syst%C3%A8me_d'exploitation_temps_r%C3%A9el) (fichier `/etc/security/limits.d/audio.conf` présent) et ajouter l'utilisateur au groupe `audio`).
* Paquets `python3 python3-mido python3-rtmidi librtmidi5`
