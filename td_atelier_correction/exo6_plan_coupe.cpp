// Exercice 6 — Plan de coupe (tableaux 2D)
// Objectif : manipulation de tableaux 2D avec pointeurs sur lignes

#include <iostream>
#include <iomanip>

using namespace std;

// Fonction qui affiche le plan de coupe
void afficher_plan(int (*m)[5], int lignes, const string& titre) {
    cout << titre << endl;
    cout << "Adresse du plan : " << m << endl;

    const string noms_lignes[4] = {"Col", "Devant", "Dos", "Manches"};

    for (int i = 0; i < lignes; ++i) {
        int (*row)[5] = m + i; // Pointeur sur la ligne i
        cout << setw(8) << noms_lignes[i] << " @" << row << " : ";

        for (int j = 0; j < 5; ++j) {
            cout << setw(3) << (*row)[j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Fonction qui pivote (échange première et dernière ligne)
void pivoter(int (*m)[5], int lignes) {
    if (lignes < 2) {
        cout << "Pas assez de lignes pour pivoter." << endl;
        return;
    }

    cout << "Pivot : échange de la ligne 0 et la ligne " << (lignes - 1) << endl;
    cout << "  Adresse ligne 0 : " << (m + 0) << endl;
    cout << "  Adresse ligne " << (lignes - 1) << " : " << (m + lignes - 1) << endl << endl;

    // Échange élément par élément
    for (int j = 0; j < 5; ++j) {
        int temp = (*(m + 0))[j];
        (*(m + 0))[j] = (*(m + lignes - 1))[j];
        (*(m + lignes - 1))[j] = temp;
    }
}

int main() {
    cout << "=== Exercice 6 : Plan de coupe ===" << endl;
    cout << "Scénario : Simulation d'un plan de coupe avant de poser le patron" << endl << endl;

    // Patron simplifié 2D (en cm)
    // Ligne 0 = col, ligne 1 = devant, ligne 2 = dos, ligne 3 = manches
    int plan[4][5] = {
        {10, 12, 11, 10, 12},  // Col
        {45, 50, 48, 46, 49},  // Devant
        {46, 51, 49, 47, 50},  // Dos
        {55, 58, 57, 56, 59}   // Manches
    };

    int lignes = 4;

    // Affichage initial
    afficher_plan(plan, lignes, "Plan de coupe initial :");

    // Pivot : échange col et manches
    pivoter(plan, lignes);

    // Affichage après pivot
    afficher_plan(plan, lignes, "Plan de coupe après pivot :");

    cout << "Explication :" << endl;
    cout << "  - La ligne 'Col' (indices [0][...]) est maintenant en position 0" << endl;
    cout << "    mais contient les valeurs qui étaient dans 'Manches'" << endl;
    cout << "  - La ligne 'Manches' (indices [3][...]) est maintenant en position 3" << endl;
    cout << "    mais contient les valeurs qui étaient dans 'Col'" << endl;
    cout << "  - Les lignes 'Devant' et 'Dos' n'ont pas changé" << endl;
    cout << endl;

    cout << "Manipulation réussie sans copie de la matrice complète." << endl;

    return 0;
}
