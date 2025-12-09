// exemple_utilisation.cpp
// Exemple d'utilisation de la bibliothèque atelier_couture
// Compile avec: g++ -std=c++17 exemple_utilisation.cpp atelier_couture.cpp -o exemple

#include "atelier_couture.hpp"
#include <iostream>

using namespace std;

int main() {
    cout << "=== Exemple d'utilisation de atelier_couture.hpp ===" << endl << endl;

    // ========================================================================
    // Exemple 1 : Étalonner un ruban
    // ========================================================================
    cout << "1. Étalonnage du ruban :" << endl;
    double mesure = 152.4;
    cout << "   Avant : " << mesure << " cm" << endl;
    etalonner(&mesure, 0.8);
    cout << "   Après : " << mesure << " cm" << endl << endl;

    // ========================================================================
    // Exemple 2 : Créer et ajuster des clients
    // ========================================================================
    cout << "2. Création et ajustement de clients :" << endl;
    Client awa = {"Awa", 153.2, 145.0};
    cout << "   Avant ajustement : " << awa.nom << " - " << awa.longueur_boubou << " cm" << endl;
    ajuster_longueur(awa, -2.0);
    cout << "   Après ajustement : " << awa.nom << " - " << awa.longueur_boubou << " cm" << endl << endl;

    // ========================================================================
    // Exemple 3 : Calculer la surface des rouleaux
    // ========================================================================
    cout << "3. Calcul de surface des rouleaux :" << endl;
    Rouleau wax = {"wax", 1.40, 12.0};
    double surf = surface(&wax);
    cout << "   Rouleau de " << wax.tissu << " : " << surf << " m²" << endl << endl;

    // ========================================================================
    // Exemple 4 : Découper un rouleau
    // ========================================================================
    cout << "4. Découpe d'un rouleau :" << endl;
    Rouleau bazin = {"bazin", 1.50, 10.0};
    double bandes[3] = {3.0, 3.0, 3.0};
    cout << "   Longueur avant découpe : " << bazin.longueur << " m" << endl;
    decouper(bazin, bandes, 3);
    cout << "   Longueur après découpe : " << bazin.longueur << " m" << endl;
    cout << "   Bandes obtenues : " << bandes[0] << ", " << bandes[1] << ", " << bandes[2] << " m" << endl << endl;

    // ========================================================================
    // Exemple 5 : Carnet de commandes
    // ========================================================================
    cout << "5. Gestion du carnet de commandes :" << endl;
    Client mame = {"Mame", 158.0, 148.0};
    Client khadim = {"Khadim", 165.0, 150.0};

    Client* carnet[3] = {&awa, &mame, &khadim};
    afficher_carnet(carnet, 3, "   Carnet actuel :");

    Client* trouve = chercher(carnet, 3, "Mame");
    if (trouve != nullptr) {
        cout << "   Client trouvé : " << trouve->nom << endl;
    }

    cout << endl;

    // ========================================================================
    // Exemple 6 : Plan de coupe
    // ========================================================================
    cout << "6. Manipulation d'un plan de coupe :" << endl;
    int plan[4][5] = {
        {10, 12, 11, 10, 12},
        {45, 50, 48, 46, 49},
        {46, 51, 49, 47, 50},
        {55, 58, 57, 56, 59}
    };

    afficher_plan(plan, 4, "   Plan initial :");
    pivoter(plan, 4);
    afficher_plan(plan, 4, "   Plan après pivot :");

    cout << "=== Fin de l'exemple ===" << endl;

    return 0;
}
