// atelier_couture.hpp
// Header file pour les TD Pointeurs & Couture
// Contient toutes les structures et déclarations de fonctions

#ifndef ATELIER_COUTURE_HPP
#define ATELIER_COUTURE_HPP

#include <string>

// ============================================================================
// STRUCTURES
// ============================================================================

// Structure représentant un client de l'atelier
struct Client {
    std::string nom;
    double tour_poitrine;   // cm
    double longueur_boubou; // cm
};

// Structure représentant un rouleau de tissu
struct Rouleau {
    std::string tissu;   // "wax", "bazin", "brodé"
    double largeur;      // m
    double longueur;     // m
};

// ============================================================================
// FONCTIONS - Exercice 1 : Étalonner le ruban
// ============================================================================

// Ajoute une correction au ruban via pointeur
void etalonner(double* ruban, double correction);

// ============================================================================
// FONCTIONS - Exercice 2 : Mesures clients
// ============================================================================

// Ajuste la longueur du boubou d'un client via référence
void ajuster_longueur(Client& c, double ourlet);

// ============================================================================
// FONCTIONS - Exercice 3 : Surface des rouleaux
// ============================================================================

// Calcule la surface d'un rouleau (largeur × longueur)
// Protège contre nullptr
double surface(const Rouleau* r);

// ============================================================================
// FONCTIONS - Exercice 4 : Découpe en bandes
// ============================================================================

// Découpe un rouleau en bandes et met à jour sa longueur
// Si la somme dépasse, la dernière bande est raccourcie
void decouper(Rouleau& r, double* bandes, int nbBandes);

// ============================================================================
// FONCTIONS - Exercice 5 : Carnet de commandes
// ============================================================================

// Recherche un client par nom dans le carnet
// Retourne le pointeur ou nullptr si non trouvé
Client* chercher(Client** carnet, int n, const std::string& nom);

// Affiche le contenu du carnet de commandes
void afficher_carnet(Client** carnet, int n, const std::string& titre);

// ============================================================================
// FONCTIONS - Exercice 6 : Plan de coupe
// ============================================================================

// Affiche un plan de coupe 2D
void afficher_plan(int (*m)[5], int lignes, const std::string& titre);

// Pivote le plan en échangeant la première et la dernière ligne
void pivoter(int (*m)[5], int lignes);

#endif // ATELIER_COUTURE_HPP
