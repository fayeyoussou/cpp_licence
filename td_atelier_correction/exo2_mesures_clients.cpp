// Exercice 2 — Mesures clients (références)
// Objectif : utiliser des références pour modifier des structures et parcourir avec des pointeurs

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Client {
    string nom;
    double tour_poitrine;   // cm
    double longueur_boubou; // cm
};

// Fonction qui ajuste la longueur du boubou via référence
void ajuster_longueur(Client& c, double ourlet) {
    cout << "Ajustement pour " << c.nom << " : "
         << (ourlet >= 0 ? "+" : "") << ourlet << " cm" << endl;
    c.longueur_boubou += ourlet;
}

int main() {
    cout << "=== Exercice 2 : Mesures clients ===" << endl;
    cout << "Scénario : Ajustement de 3 tenues avant le grand baptême" << endl << endl;

    // Tableau statique de 3 clients
    Client clients[3] = {
        {"Awa", 152.4, 145.0},
        {"Mame", 158.0, 148.0},
        {"Khadim", 165.0, 150.0}
    };

    // Ajustements à appliquer
    double ajustements[3] = {-2.0, 1.0, 0.0};

    cout << "État initial des clients :" << endl;
    cout << setw(10) << "Nom" << " | "
         << setw(15) << "Tour poitrine" << " | "
         << setw(15) << "Longueur" << " | "
         << "Adresse" << endl;
    cout << string(70, '-') << endl;

    Client* p = clients;
    for (int i = 0; i < 3; ++i, ++p) {
        cout << setw(10) << p->nom << " | "
             << setw(15) << p->tour_poitrine << " | "
             << setw(15) << p->longueur_boubou << " | "
             << p << endl;
    }

    cout << endl << "Application des ajustements :" << endl;
    p = clients;
    for (int i = 0; i < 3; ++i, ++p) {
        ajuster_longueur(*p, ajustements[i]);
    }

    cout << endl << "État final des clients :" << endl;
    cout << setw(10) << "Nom" << " | "
         << setw(15) << "Tour poitrine" << " | "
         << setw(15) << "Longueur" << " | "
         << "Adresse" << endl;
    cout << string(70, '-') << endl;

    p = clients;
    for (int i = 0; i < 3; ++i, ++p) {
        cout << setw(10) << p->nom << " | "
             << setw(15) << p->tour_poitrine << " | "
             << setw(15) << p->longueur_boubou << " | "
             << p << endl;
    }

    return 0;
}
