// atelier_couture.cpp
// Implémentation des fonctions pour les TD Pointeurs & Couture

#include "atelier_couture.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

// ============================================================================
// Exercice 1 : Étalonner le ruban
// ============================================================================

void etalonner(double* ruban, double correction) {
    if (ruban == nullptr) {
        cout << "Erreur : pointeur nul" << endl;
        return;
    }
    *ruban += correction;
}

// ============================================================================
// Exercice 2 : Mesures clients
// ============================================================================

void ajuster_longueur(Client& c, double ourlet) {
    c.longueur_boubou += ourlet;
}

// ============================================================================
// Exercice 3 : Surface des rouleaux
// ============================================================================

double surface(const Rouleau* r) {
    if (r == nullptr) {
        cout << "Erreur : pointeur de rouleau nul" << endl;
        return 0.0;
    }
    return r->largeur * r->longueur;
}

// ============================================================================
// Exercice 4 : Découpe en bandes
// ============================================================================

void decouper(Rouleau& r, double* bandes, int nbBandes) {
    double somme_demandee = 0.0;
    for (int i = 0; i < nbBandes; ++i) {
        somme_demandee += *(bandes + i);
    }

    double longueur_restante = r.longueur;

    for (int i = 0; i < nbBandes; ++i) {
        double bande_demandee = *(bandes + i);

        if (bande_demandee <= longueur_restante) {
            longueur_restante -= bande_demandee;
        } else {
            // Dernière bande raccourcie
            *(bandes + i) = longueur_restante;
            longueur_restante = 0.0;
            break;
        }
    }

    r.longueur = longueur_restante;
}

// ============================================================================
// Exercice 5 : Carnet de commandes
// ============================================================================

Client* chercher(Client** carnet, int n, const string& nom) {
    for (int i = 0; i < n; ++i) {
        if (carnet[i]->nom == nom) {
            return carnet[i];
        }
    }
    return nullptr;
}

void afficher_carnet(Client** carnet, int n, const string& titre) {
    cout << titre << endl;
    cout << setw(10) << "Nom" << " | "
         << setw(15) << "Tour poitrine" << " | "
         << setw(15) << "Longueur" << " | "
         << "Adresse" << endl;
    cout << string(70, '-') << endl;

    for (int i = 0; i < n; ++i) {
        cout << setw(10) << carnet[i]->nom << " | "
             << setw(15) << carnet[i]->tour_poitrine << " | "
             << setw(15) << carnet[i]->longueur_boubou << " | "
             << carnet[i] << endl;
    }
    cout << endl;
}

// ============================================================================
// Exercice 6 : Plan de coupe
// ============================================================================

void afficher_plan(int (*m)[5], int lignes, const string& titre) {
    cout << titre << endl;
    cout << "Adresse du plan : " << m << endl;

    const string noms_lignes[4] = {"Col", "Devant", "Dos", "Manches"};

    for (int i = 0; i < lignes; ++i) {
        int (*row)[5] = m + i;
        cout << setw(8) << noms_lignes[i] << " @" << row << " : ";

        for (int j = 0; j < 5; ++j) {
            cout << setw(3) << (*row)[j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void pivoter(int (*m)[5], int lignes) {
    if (lignes < 2) {
        cout << "Pas assez de lignes pour pivoter." << endl;
        return;
    }

    // Échange élément par élément entre première et dernière ligne
    for (int j = 0; j < 5; ++j) {
        int temp = (*(m + 0))[j];
        (*(m + 0))[j] = (*(m + lignes - 1))[j];
        (*(m + lignes - 1))[j] = temp;
    }
}
