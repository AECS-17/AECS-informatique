# Langage Bash et Ligne de commande

Dans cette session nous verrons comment [utiliser la ligne de commande](https://fr.wikipedia.org/wiki/Interface_en_ligne_de_commande) avec l’interpréteur [Bash](https://fr.wikipedia.org/wiki/Bourne-Again_shell). Elle est souvent l’interface de prédilection des [hackeurs dans les œuvres de fictions](https://fr.wikipedia.org/wiki/Hacker_(s%C3%A9curit%C3%A9_informatique)#Hackeurs_dans_les_%C5%93uvres_de_fictions). Ancêtre des interfaces graphiques, elle reste fondamentale pour les ingénieurs en informatique et cette petite introduction sera fort utile pour les sessions ultérieures.

![Capture d’écran](https://raw.githubusercontent.com/AECS-17/AECS-informatique/master/ligne-de-commande/capture.png)

## Objectifs pédagogiques

* Utilisation de l’aide (`--help`, `man`)
* Commandes manipuler des fichiers et dossiers:
     `cp`,
     `ls`,
     `mkdir`,
     `mv`,
     `pwd`,
     `rm`,
     `rmdir`,
     `touch`
* Commandes manipuler le contenu de fichiers textes:
     `cat`,
     `echo` (redirection `>`, `>>`),
     `sed` (substitution simple)
     `sort`,
     `wc`
* Commandes pour les processus: `kill`, `ps`, `bg`, `fg`, `Ctrl+C`, `Ctrl+Z`, `&`
* Commandes pour le partage entre machines:
   - Téléchargement de page: `wget`
   - Session à distance: `ip address`, `scp`, `ssh`
   - Logiciel de gestion de versions: `git` (clone, log, status, diff, etc)

## Déroulement possible de la session

On pourra utiliser une console virtuelle pour se forcer à n'utiliser que la ligne de commande.

0. Introduction. Exemple :
   On dispose de 100 photos au format JPEG et on souhaite les redimensionner,
   changer leur qualité et les compresser dans une archive ZIP afin de réduire
   la taille des fichiers. Comment s’y prendre ? Que faire si à la fin les
   fichiers sont encore trop volumineux pour les transférer (e.g. par courriel).
1. Tester les commandes `pwd`, `pwd --help`, `man pwd`.
2. Utiliser les commandes pour créer/Supprimer/Renommer des fichiers et dossiers, vérifier avec `ls`.
3. Utiliser `echo` et `cat` pour créer et afficher des fichiers avec plusieurs lignes (e.g. liste de personnes).
4. Utiliser `sort`, `uniq`, `wc`, `sed` sur ces fichiers.
5. Illustrer les commandes de processus avec le programme [count.sh](https://github.com/AECS-17/AECS-informatique/blob/master/ligne-de-commande/count.sh)`.
6. Télécharger une page web avec `wget`.
7. Envoyer la page sur une autre machine et se connecter à cette machine (`scp`, `ssh`). On pourra utiliser l'adresse IP locale retournée pas `ip address`.
8. Cloner ce dépôt `git https://github.com/AECS-17/AECS-informatique.git` et
   présenter les commandes et concepts de base selon le temps disponible.

## Installation

L’environnement suivant sera mis à disposition pour cette session:

* Linux Mint >= 21
* Paquets `bash coreutils procps sed wget openssh-client git iproute2`
