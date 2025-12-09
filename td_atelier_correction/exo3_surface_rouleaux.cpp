// Exercice 3 — Surface des rouleaux
// Objectif : allocation dynamique, arithmétique de pointeurs, protection contre nullptr

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Rouleau {
    string tissu;   // "wax", "bazin", "brodé"
    double largeur; // m
    double longueur; // m
};

// Fonction qui calcule la surface d'un rouleau
double surface(const Rouleau* r) {
    if (r == nullptr) {
        cout << "Erreur : pointeur de rouleau nul" << endl;
        return 0.0;
    }
    return r->largeur * r->longueur;
}

int main() {
    cout << "=== Exercice 3 : Surface des rouleaux ===" << endl;
    cout << "Scénario : Mesure du stock disponible pour boubous assortis" << endl << endl;

    int n = 3;
    // Allocation dynamique de 3 rouleaux
    Rouleau* stock = new Rouleau[n];

    // Initialisation des rouleaux
    stock[0] = {"wax", 1.40, 12.0};
    stock[1] = {"bazin", 1.50, 10.0};
    stock[2] = {"brodé", 1.20, 8.0};

    cout << "Détail des rouleaux en stock :" << endl;
    cout << setw(10) << "Tissu" << " | "
         << setw(12) << "Largeur (m)" << " | "
         << setw(13) << "Longueur (m)" << " | "
         << setw(12) << "Surface (m²)" << " | "
         << "Adresse" << endl;
    cout << string(80, '-') << endl;

    double surface_totale = 0.0;

    // Parcours avec arithmétique de pointeurs
    for (Rouleau* p = stock; p < stock + n; ++p) {
        double surf = surface(p);
        surface_totale += surf;

        cout << setw(10) << p->tissu << " | "
             << setw(12) << p->largeur << " | "
             << setw(13) << p->longueur << " | "
             << setw(12) << fixed << setprecision(2) << surf << " | "
             << p << endl;
    }

    cout << string(80, '-') << endl;
    cout << "Surface totale disponible : " << surface_totale << " m²" << endl;

    // Test de protection contre nullptr
    cout << endl << "Test avec pointeur nul :" << endl;
    double surf_null = surface(nullptr);
    cout << "Surface retournée : " << surf_null << " m²" << endl;

    // Libération de la mémoire
    delete[] stock;
    cout << endl << "Mémoire libérée avec succès." << endl;

    return 0;
}
