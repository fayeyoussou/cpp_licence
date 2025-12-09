# TD Pointeurs & Couture - Corrections

Ce dossier contient les corrections des exercices du TD "Pointeurs & Couture" de l'atelier de Dakar.

## Structure des fichiers

### Fichiers principaux

- **atelier_couture.hpp** : Header contenant toutes les structures et déclarations de fonctions
- **atelier_couture.cpp** : Implémentation de toutes les fonctions

### Corrections des exercices (fichiers autonomes)

- **exo1_etalonner_ruban.cpp** : Étalonnage du ruban (pointeurs de base)
- **exo2_mesures_clients.cpp** : Mesures clients (références et parcours de tableaux)
- **exo3_surface_rouleaux.cpp** : Surface des rouleaux (allocation dynamique)
- **exo4_decoupe_bandes.cpp** : Découpe en bandes (arithmétique de pointeurs)
- **exo5_carnet_commandes.cpp** : Carnet de commandes (tableaux de pointeurs, tri)
- **exo6_plan_coupe.cpp** : Plan de coupe (tableaux 2D)

### Fichier exemple

- **exemple_utilisation.cpp** : Exemple d'utilisation de la bibliothèque atelier_couture

## Compilation

### Option 1 : Compiler un exercice individuel

Chaque exercice est autonome et peut être compilé séparément :

```bash
g++ -std=c++17 exo1_etalonner_ruban.cpp -o exo1
./exo1

g++ -std=c++17 exo2_mesures_clients.cpp -o exo2
./exo2

# etc...
```

### Option 2 : Utiliser la bibliothèque atelier_couture

Pour créer votre propre programme utilisant les structures et fonctions :

```bash
g++ -std=c++17 exemple_utilisation.cpp atelier_couture.cpp -o exemple
./exemple
```

Ou pour compiler votre propre fichier :

```bash
g++ -std=c++17 mon_fichier.cpp atelier_couture.cpp -o mon_programme
./mon_programme
```

### Option 3 : Compiler tous les exercices d'un coup

```bash
#!/bin/bash
for i in {1..6}; do
    g++ -std=c++17 exo${i}_*.cpp -o exo${i}
    echo "Compilé : exo${i}"
done
```

## Contenu de chaque exercice

### Exercice 1 - Étalonner le ruban
- Manipulation de pointeurs pour modifier une valeur
- Fonction : `void etalonner(double* ruban, double correction)`

### Exercice 2 - Mesures clients
- Utilisation de références pour modifier des structures
- Parcours de tableaux avec arithmétique de pointeurs
- Fonction : `void ajuster_longueur(Client& c, double ourlet)`

### Exercice 3 - Surface des rouleaux
- Allocation dynamique de tableaux
- Protection contre `nullptr`
- Calcul avec arithmétique de pointeurs
- Fonction : `double surface(const Rouleau* r)`

### Exercice 4 - Découpe en bandes
- Manipulation de tableaux avec pointeurs uniquement
- Modification de structures par référence
- Fonction : `void decouper(Rouleau& r, double* bandes, int nbBandes)`

### Exercice 5 - Carnet de commandes
- Tableaux de pointeurs vers des structures
- Tri à bulles avec pointeurs
- Recherche avec retour de pointeur ou `nullptr`
- Fonctions :
  - `Client* chercher(Client** carnet, int n, const string& nom)`
  - `void afficher_carnet(Client** carnet, int n, const string& titre)`

### Exercice 6 - Plan de coupe
- Manipulation de tableaux 2D avec pointeurs sur lignes
- Pointeur sur tableau de taille fixe : `int (*m)[5]`
- Fonctions :
  - `void afficher_plan(int (*m)[5], int lignes, const string& titre)`
  - `void pivoter(int (*m)[5], int lignes)`

## Points clés abordés

- ✓ Pointeurs et déréférencement
- ✓ Références
- ✓ Arithmétique de pointeurs
- ✓ Allocation dynamique (`new` / `delete[]`)
- ✓ Tableaux de pointeurs
- ✓ Pointeurs sur structures
- ✓ Tableaux 2D avec pointeurs
- ✓ Protection contre `nullptr`
- ✓ Passage par valeur vs référence vs pointeur
- ✓ Affichage des adresses mémoire

## Sécurité mémoire

Tous les exercices respectent les bonnes pratiques :
- Protection contre les pointeurs nuls
- Libération de la mémoire dynamique avec `delete[]`
- Pas de fuites mémoire
- Vérifications avant déréférencement

## Auteur

Corrections pour le TD "Pointeurs & Couture" - Atelier de Dakar
