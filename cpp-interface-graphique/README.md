# Programmation C++ et interface graphique

Dans cette session, nous allons créer une interface graphique pour une application simple à l’aide du langage [C++](https://fr.wikipedia.org/wiki/C_(langage)). Nous utiliserons pour cela la [bibliothèque wxWidgets](https://en.wikipedia.org/wiki/WxWidgets).

![Capture d’écran](https://raw.githubusercontent.com/AECS-17/AECS-informatique/master/cpp-interface-graphique/capture.png)

## Objectifs pédagogiques

* Syntaxe de base C++: classes, méthodes, membres, héritage, etc
* Compilation d’un programme avec CMake.
* Élément d’une interface graphique, évènements

## Déroulement possible de la session

0. Introduction.
1. Compilation avec `cmake` et execution du programme.
2. Étudier [main.cc](https://github.com/AECS-17/AECS-informatique/blob/master/cpp-interface-graphique/main.cc)
3. Ajouter des éléments dans le menu.
4. Implémenter des méthodes répondant à l’interaction de l’utilisateur.
5. Ajouter d'autres éléments et actions selon le temps disponible (voir [la documentation wxWidgets](https://www.wxwidgets.org/docs/)):
   - [wxTextCtrl](https://docs.wxwidgets.org/3.0/classwx_text_ctrl.html)
   - [wxMessageDialog](https://docs.wxwidgets.org/3.0/classwx_message_dialog.html)
   - [wxButton](https://docs.wxwidgets.org/3.0/classwx_button.html)
   - [wxCheckBox](https://docs.wxwidgets.org/3.0/classwx_check_box.html)
   - [wxChoice](https://docs.wxwidgets.org/3.0/classwx_choice.html)
   - [wxToolBar](https://docs.wxwidgets.org/3.0/classwx_tool_bar.html)
   - ...

## Installation

L’environnement suivant sera mis à disposition pour cette session:

* Linux Mint >= 21
* Paquets `cmake g++ wx-common libwxbase3.0-dev libwxgtk3.0-gtk3-dev libwxgtk-webview3.0-gtk3-dev`
