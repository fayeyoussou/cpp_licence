// Exercice 5 — Carnet de commandes (pointeurs de struct)
// Objectif : tableaux de pointeurs, tri, recherche

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Client {
    string nom;
    double tour_poitrine;   // cm
    double longueur_boubou; // cm
};

// Fonction de recherche dans le carnet
Client* chercher(Client** carnet, int n, const string& nom) {
    for (int i = 0; i < n; ++i) {
        if (carnet[i]->nom == nom) {
            return carnet[i];
        }
    }
    return nullptr;
}

// Fonction d'affichage du carnet
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

int main() {
    cout << "=== Exercice 5 : Carnet de commandes ===" << endl;
    cout << "Scénario : Classement des commandes de la plus courte à la plus longue" << endl << endl;

    // Création des clients (après les ajustements de l'exo 2)
    Client awa = {"Awa", 152.4, 143.0};      // 145 - 2
    Client mame = {"Mame", 158.0, 149.0};    // 148 + 1
    Client khadim = {"Khadim", 165.0, 150.0}; // 150 + 0

    int n = 3;
    // Allocation dynamique d'un tableau de pointeurs
    Client** carnet = new Client*[n];

    // Initialisation des pointeurs (pas de copie)
    carnet[0] = &awa;
    carnet[1] = &mame;
    carnet[2] = &khadim;

    afficher_carnet(carnet, n, "Carnet initial :");

    // Tri à bulles par longueur_boubou croissante
    cout << "Tri des commandes par longueur croissante..." << endl << endl;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (carnet[j]->longueur_boubou > carnet[j + 1]->longueur_boubou) {
                // Échange des pointeurs
                Client* temp = carnet[j];
                carnet[j] = carnet[j + 1];
                carnet[j + 1] = temp;
            }
        }
    }

    afficher_carnet(carnet, n, "Carnet trié :");

    // Test de recherche pour "Mame"
    cout << "Recherche de 'Mame' dans le carnet..." << endl;
    Client* resultat = chercher(carnet, n, "Mame");
    if (resultat != nullptr) {
        cout << "Client trouvé : " << resultat->nom
             << " (longueur : " << resultat->longueur_boubou << " cm) @"
             << resultat << endl;
    } else {
        cout << "Client non trouvé." << endl;
    }
    cout << endl;

    // Test de recherche pour "Rokhaya" (n'existe pas)
    cout << "Recherche de 'Rokhaya' dans le carnet..." << endl;
    resultat = chercher(carnet, n, "Rokhaya");
    if (resultat != nullptr) {
        cout << "Client trouvé : " << resultat->nom << endl;
    } else {
        cout << "Client non trouvé (nullptr retourné)." << endl;
    }
    cout << endl;

    // Application d'une remise de 2 cm à Mame
    cout << "Application d'une remise de 2 cm à Mame..." << endl;
    Client* mame_ptr = chercher(carnet, n, "Mame");
    if (mame_ptr != nullptr) {
        cout << "Avant : " << mame_ptr->nom << " - "
             << mame_ptr->longueur_boubou << " cm" << endl;
        mame_ptr->longueur_boubou -= 2.0;
        cout << "Après : " << mame_ptr->nom << " - "
             << mame_ptr->longueur_boubou << " cm" << endl << endl;
    }

    // Réaffichage du carnet (maintenant il n'est plus trié car Mame a changé)
    afficher_carnet(carnet, n, "Carnet après modification de Mame :");

    // Libération de la mémoire
    delete[] carnet;
    cout << "Mémoire libérée avec succès." << endl;

    return 0;
}
