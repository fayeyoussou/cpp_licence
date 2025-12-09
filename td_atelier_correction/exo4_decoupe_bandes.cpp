// Exercice 4 — Découpe en bandes
// Objectif : manipulation de tableaux via arithmétique de pointeurs, modification par référence

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Rouleau {
    string tissu;
    double largeur;  // m
    double longueur; // m
};

// Fonction qui découpe le rouleau en bandes
void decouper(Rouleau& r, double* bandes, int nbBandes) {
    cout << "Découpe du rouleau de " << r.tissu
         << " (longueur disponible : " << r.longueur << " m)" << endl;

    double somme_demandee = 0.0;
    for (int i = 0; i < nbBandes; ++i) {
        somme_demandee += *(bandes + i);
    }

    cout << "Longueur totale demandée : " << somme_demandee << " m" << endl;

    if (somme_demandee > r.longueur) {
        cout << "Attention : longueur demandée supérieure au stock!" << endl;
        cout << "Ajustement de la dernière bande..." << endl;
    }

    double longueur_restante = r.longueur;

    cout << endl << "Bandes découpées :" << endl;
    for (int i = 0; i < nbBandes; ++i) {
        double bande_demandee = *(bandes + i);

        if (bande_demandee <= longueur_restante) {
            // Bande complète
            cout << "  Bande " << (i + 1) << " : "
                 << bande_demandee << " m (complète)" << endl;
            longueur_restante -= bande_demandee;
        } else {
            // Dernière bande raccourcie
            *(bandes + i) = longueur_restante;
            cout << "  Bande " << (i + 1) << " : "
                 << *(bandes + i) << " m (raccourcie de "
                 << bande_demandee << " m à " << *(bandes + i) << " m)" << endl;
            longueur_restante = 0.0;
            break;
        }
    }

    // Mise à jour de la longueur du rouleau
    r.longueur = longueur_restante;
}

int main() {
    cout << "=== Exercice 4 : Découpe en bandes ===" << endl;
    cout << "Scénario : Commande de 4 empiècements identiques en bazin" << endl << endl;

    // Initialisation du rouleau de bazin
    Rouleau bazin = {"bazin", 1.50, 10.0};

    cout << "État initial du rouleau :" << endl;
    cout << "  Tissu : " << bazin.tissu << endl;
    cout << "  Largeur : " << bazin.largeur << " m" << endl;
    cout << "  Longueur : " << bazin.longueur << " m" << endl << endl;

    // Bandes demandées (4 × 3 m = 12 m, mais on n'a que 10 m)
    int nbBandes = 4;
    double bandes[4] = {3.0, 3.0, 3.0, 3.0};

    cout << "Bandes demandées : ";
    for (int i = 0; i < nbBandes; ++i) {
        cout << bandes[i] << " m";
        if (i < nbBandes - 1) cout << ", ";
    }
    cout << endl << endl;

    // Découpe
    decouper(bazin, bandes, nbBandes);

    cout << endl << "État final du rouleau :" << endl;
    cout << "  Longueur restante : " << bazin.longueur << " m" << endl;

    cout << endl << "Bandes réellement obtenues : ";
    for (int i = 0; i < nbBandes; ++i) {
        cout << *(bandes + i) << " m";
        if (i < nbBandes - 1) cout << ", ";
    }
    cout << endl;

    return 0;
}
