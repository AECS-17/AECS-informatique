# Rust et parallélisme

Dans cette session, nous allons calculer la longueur d’une courbe en parallèle sur plusieurs processeurs, à l’aide du langage [Rust](https://fr.wikipedia.org/wiki/Rust_(langage)).

![Capture d’écran](https://raw.githubusercontent.com/AECS-17/AECS-informatique/master/rust-parallelisme/capture.png)

## Objectifs pédagogiques

* Syntaxe et sémantique de base Rust, outil `cargo`.
* Parallélisme, vérou, temps d’exécution.
* Courbe de Bézier cubique, approximation numérique.

## Déroulement possible de la session

0. Introduction
1. Dans le dossier `bezier`, exécuter `cargo run`.
2. Étudier [src/main.rs](https://github.com/AECS-17/AECS-informatique/blob/master/rust-et-parallelisme/bezier/src/main.rs), le modifier pour générer un fichier svg `curve.svg` et visualiser l’image de la courbe `curve` dans inkscape.
3. Explication des [coubes de Bézier cubique](https://fr.wikipedia.org/wiki/Courbe_de_B%C3%A9zier#Courbes_de_B%C3%A9zier_cubiques).
4. Définir une fonction pour créer un segment de droite de `(x0, y0)` à
   `(x3, y3)` en utilisant leur milieu comme poignées de Bézier.
5. Tester `dump_to_svg` et `approximate_length` avec divers polygones simple : carré, rectangle, losange, triangles…
6. Compiler le programme original en mode "release" avec la commande `cargo build --release` et mesure son temps d’exécution avec `time target/release/bezier`.
7. Explication parallélisme, execution de `lscpu` pour déterminer le nombre de threads.
8. Ajouter [crossbeam](https://docs.rs/crossbeam/0.8.0/crossbeam/index.html] dans les dépendences de `Cargo.toml` et executer `cargo update` pour les mettre à jour.
9. Faire fonctionner le code de calcul de longueur de morceaux de courbe en mode parallèle.
10. Analyser et faire fonctionner le programme suivant. Essayer de l’exécuter pluusieurs fois. Expliquer l’intérêt de `Mutex` et de `Arc`.
```rust
let vector_mutex = Arc::new(Mutex::new(Vec::new()));
crossbeam::scope(|spawner| {
    for thread_index in 0..thread_count {
        let vector_mutex_clone = Arc::clone(&vector_mutex);
        spawner.spawn(move |_| {
            println!("Starting thread {}", thread_index);
            loop {
                {
                    let mut vector = vector_mutex_clone.lock().unwrap();
                    if (vector.len() == thread_count - 1 - thread_index) {
                        vector.push(thread_index);
                        break;
                    }
                }
                thread::sleep(time::Duration::from_millis(100));
            }
         });
    }
}).unwrap();
println!("Output: {:?}", vector_mutex.lock().unwrap());
```
11. Adapter le calcul de longueur des morceaux de courbe en parallèle pour obtenir la longueur totale de la courbe. Comparer avec le temps d’exécution antérieur.
12. Comparer les temps d’exécution avec des valeurs différentes de `POINTS_PER_BEZIER_SEGMENT`.

## Installation

L’environnement suivant sera mis à disposition pour cette session:

* Linux Mint >= 20
* `cargo`