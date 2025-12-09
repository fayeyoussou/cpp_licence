// Exercice 1 — Étalonner le ruban
// Objectif : manipulation de pointeurs pour modifier une valeur

#include <iostream>
#include <iomanip>

using namespace std;

// Fonction qui ajoute la correction au ruban via pointeur
void etalonner(double* ruban, double correction) {
    if (ruban == nullptr) {
        cout << "Erreur : pointeur nul" << endl;
        return;
    }

    cout << "Avant étalonnage : ruban = " << *ruban << " cm @" << ruban << endl;
    *ruban += correction;
    cout << "Après étalonnage : ruban = " << *ruban << " cm @" << ruban << endl;
}

int main() {
    cout << "=== Exercice 1 : Étalonner le ruban ===" << endl;
    cout << "Scénario : La chaleur a détendu le ruban (il manque 0.8 cm)" << endl;
    cout << "Mesure brute d'Awa = 152.4 cm, correction +0.8 cm" << endl << endl;

    double mesure_awa = 152.4;
    double correction = 0.8;

    cout << "Mesure initiale : " << mesure_awa << " cm" << endl;
    cout << "Correction à appliquer : +" << correction << " cm" << endl << endl;

    // Appel de la fonction avec le pointeur sur mesure_awa
    etalonner(&mesure_awa, correction);

    cout << endl << "Résultat final : " << mesure_awa << " cm" << endl;
    cout << "Tour de poitrine réel d'Awa : " << mesure_awa << " cm" << endl;

    return 0;
}