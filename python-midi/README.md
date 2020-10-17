# Programmation Python et musique MIDI

Introduction à la programmation en utilisant le langage
[Python](https://fr.wikipedia.org/wiki/Python_(langage)) et une librarie pour
manipuler de la musique au
[format MIDI](https://fr.wikipedia.org/wiki/Musical_Instrument_Digital_Interface).

![Capture d’écran](https://raw.githubusercontent.com/fred-wang/AECS-informatique/master/python-midi/capture.png)

## Objectifs pédagogiques

1. Aperçu de logiciels de musique assistée par ordinateur
   - Clavier virtuel, connection MIDI, synthétiseur.
   - Éditeur de partition musicale.

2. Introduction à la programmation
  - Bases du langage Python: variables, boucle, interface entrée/sortie.
  - Librairie [python-mito](https://mido.readthedocs.io/en/latest/).

## Exemples de programmes

Les exemples suivants seront pris comme point de départ:

- `ports.py`: Afficher les ports MIDI disponibles.
- `listen.py`: Créer une entrée MIDI et afficher les messages MIDI reçu.
- `play.py`: Créer une sortie MIDI et jouer les notes entrées par l’utilisateur.
- `read.py`: Creer une sortie MIDI et envoyer les messages lus depuis un fichier.

Ils pourront éventuellement être adaptés pour écrire ses propres mini-programmes intéragissant entre l'entrée au clavier MIDI, les fichiers MIDI ou la sortie audio.
