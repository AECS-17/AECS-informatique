# Programmation Python et musique MIDI

Introduction à la programmation en utilisant le langage
[Python](https://fr.wikipedia.org/wiki/Python_(langage)) et une librarie pour
manipuler de la musique au
[format MIDI](https://fr.wikipedia.org/wiki/Musical_Instrument_Digital_Interface).

![Capture d’écran](https://raw.githubusercontent.com/AECS-17/AECS-informatique/master/python-midi/capture.png)

## Objectifs pédagogiques

1. Aperçu de logiciels de musique assistée par ordinateur
   - Clavier virtuel, connection MIDI, synthétiseur.
   - Éditeur de partition musicale.

2. Introduction à la programmation
   - Bases du langage Python
   - Variables, fonctions, boucles, interfaces entrée/sortie.
   - Librairie [python-mito](https://mido.readthedocs.io/en/latest/).

## Plan

0. Introduction.
1. Connection MIDI (clavier virtuel/physique, qjackctl, qsynth)
2. [ports.py](https://github.com/AECS-17/AECS-informatique/blob/master/python-midi/ports.py): Afficher les ports MIDI disponibles.
3. [listen.py](https://github.com/AECS-17/AECS-informatique/blob/master/python-midi/listen.py): Créer une entrée MIDI et afficher les messages MIDI reçu.
4. [play.py](https://github.com/AECS-17/AECS-informatique/blob/master/python-midi/play.py): Créer une sortie MIDI et jouer les notes entrées par l’utilisateur.
5. [read-and-play.py](https://github.com/AECS-17/AECS-informatique/blob/master/python-midi/read-and-play.py): Creer une sortie MIDI et envoyer les messages lus depuis un fichier édité avec [MuseScore](https://fr.wikipedia.org/wiki/MuseScore).
6. Selon le temps disponible, écrire ses propres mini-programmes intéragissant entre l'entrée au clavier MIDI, les fichiers MIDI ou la sortie audio.
