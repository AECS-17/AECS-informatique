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
1. Ouvrez un terminal, cloner ce dépôt (si ce n'est pas déjà fait) et déplacer vous dans le dossier `python-midi`:
   ```bash
      git clone https://github.com/AECS-17/AECS-informatique.git
      cd AECS-informatique/python-midi
      ls
   ```
2. Mettre en place des connections MIDI (clavier virtuel/physique, qjackctl, qsynth) et vérifier que l'on peut jouer au clavier.
3. Étudier et exécuter [ports.py](https://github.com/AECS-17/AECS-informatique/blob/master/python-midi/ports.py): Afficher les ports MIDI disponibles et comparer avec qjackctl.
4. Étudier et exécuter [listen.py](https://github.com/AECS-17/AECS-informatique/blob/master/python-midi/listen.py). Connecter une entrée MIDI et vérifier les messages reçus. Modifier le programme pour afficher séparément valeurs de `message.note`, `message.velocity`, `message.time` et `message.type`.
5. Étudier et exécuter [play.py](https://github.com/AECS-17/AECS-informatique/blob/master/python-midi/play.py). Connecter une sortie MIDI pour jouer les notes entrées par l’utilisateur.
6. Utilisez [MuseScore](https://fr.wikipedia.org/wiki/MuseScore) pour créer un fichier MIDI (e.g. à partir de `A-E-C-Si.musicxml`).
7. Étudier et exécuter [read-and-play.py](https://github.com/AECS-17/AECS-informatique/blob/master/python-midi/read-and-play.py). Faire en sorte qu'il lise et joue la musique.
8. Selon le temps disponible, écrire ses propres mini-programmes intéragissant entre l’entrée au clavier MIDI, les fichiers MIDI ou la sortie audio (voir quelques idées dans la section suivante).

## Idées de mini-programmes

1. Modifier `listen.py` pour écrire le mini-jeu suivant : à l'aide de [random.randint](https://docs.python.org/fr/3.8/library/random.html#random.randint) une note est tirée au sort et on quitte la boucle lorsque le joueur rentre la bonne note. A chaque message, le programme peut indiquer "plus aïgue/grave" ou si le joueur "chauffe/refroidit". On peut aussi compter le temps écoulé (à l'aide de [time.time](https://docs.python.org/fr/3/library/time.html#time.time)) ou le nombre de tentatives pour trouver la bonne note.

2. Modifier `play.py` pour jouer une mélodie aléatoire avec un nombre de note, des durées et des hauteurs variables. Indication : La fonction [random.choice](https://docs.python.org/fr/3.8/library/random.html#random.choice) permet de tirer au sort un élément d'une liste.

3. Modifier `read_and_play.py` pour [transposer](https://fr.wikipedia.org/wiki/Transposition_%28musique%29) une musique MIDI en augmentant ou diminuant par une constante les notes lues à partir du fichier. Indication : Utiliser `hasattr(message, "note")` pour vérifier si un message contient une note à transposer.

4. Modifier `listen.py` pour afficher le nom de la note jouée (do, do#, ré, ...) et l'octave correspondante (1, 2, 3, 4, ...). Comparer avec VMPK (menu affichage, noms des notes). Indication : Les variables `midi_middle_C` et `note_names` de `read_and_play.py` peuvent être utiles, ainsi que les opérateurs `%` et `//` (reste et quotient de division euclidienne).

5. Modifier `play.py` pour jouer des [accords](https://fr.wikipedia.org/wiki/Accord_(musique\)). Par exemple, le programme interprète C comme l'accord de trois note "do, mi, sol" (DO majeur).

6. Modifier `read_and_play.py` pour compter chacune des notes (do, do#, ré, ...). Implémenter une heuristique pour trouver la [tonalité](https://fr.wikipedia.org/wiki/Tonalit%C3%A9) d'un morceau.

## Installation

L’environnement suivant sera mis à disposition pour cette session:

* Un clavier MIDI
* Linux Mint >= 21
* Paquets `qjackctl alsaplayer-jack vmpk qsynth musescore3`. Accepter l'activation du [temps réel](https://fr.wikipedia.org/wiki/Syst%C3%A8me_d'exploitation_temps_r%C3%A9el) (fichier `/etc/security/limits.d/audio.conf` présent) et ajouter l'utilisateur au groupe `audio`). Dans VMPK, utiliser ALSA dans les paramètres MIDI de VMPK. Dans QSynth, utiliser alsa_seq en MIDI, jack en Audio et importer les banques de son.
* Paquets `python3 python3-mido python3-rtmidi librtmidi4`

