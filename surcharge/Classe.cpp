//
// Created by youssoupha faye on 06/01/2026.
//

#include "Classe.hpp"
#include <iostream>

void Classe::ajouterEtudiant(const Etudiant& etudiant) {
    etudiants.push_back(etudiant);
}

int Classe::getId() {
    return id;
}
void Classe::setId(int id) {
    this->id = id;
}
Classe::Classe(int id) {
    this->id = id;
    this->etudiants = {};
}

Classe::Classe(int id, std::vector<Etudiant> etudiants) {
    this->id = id;
    this->etudiants = etudiants;
}


std::vector<Etudiant>& Classe::getEtudiants() {
    return etudiants;
}

const std::vector<Etudiant>& Classe::getEtudiants() const {
    return etudiants;
}
Etudiant* Classe::operator[](std::string matricule) {
    for (Etudiant & etudiant : etudiants) {
        if (etudiant.getMatricule() == matricule) {
            return &etudiant;
        }
    }
    return nullptr;
}


// Operator for adding/removing single Etudiant
Classe& Classe::operator+=(const Etudiant& etudiant) {
    this->ajouterEtudiant(etudiant);
    return *this;
}

Classe& Classe::operator-=(const std::string& matricule) {
    for (auto it = etudiants.begin(); it != etudiants.end(); ++it) {
        if (it->getMatricule() == matricule) {
            etudiants.erase(it);
            break;
        }
    }
    return *this;
}

// Merging two classes - creates new class with students from both
Classe Classe::operator+(const Classe& other) const {
    Classe result(this->id);
    result.etudiants = this->etudiants;
    for (const auto& etudiant : other.etudiants) {
        result.etudiants.push_back(etudiant);
    }
    return result;
}

// Subtracting classes - removes students that exist in other class
Classe Classe::operator-(const Classe& other) const {
    Classe result(this->id);
    for (const auto& etudiant : this->etudiants) {
        bool found = false;
        for (const auto& otherEtudiant : other.etudiants) {
            if (etudiant == otherEtudiant) {
                found = true;
                break;
            }
        }
        if (!found) {
            result.etudiants.push_back(etudiant);
        }
    }
    return result;
}

// Assignment operator - copy all students from other class
Classe& Classe::operator=(const Classe& other) {
    if (this != &other) {
        this->id = other.id;
        this->etudiants = other.etudiants;
    }
    return *this;
}

// Equality operator - compare IDs
bool Classe::operator==(const Classe& other) const {
    return this->id == other.id;
}

std::ostream& operator<<(std::ostream& os, const Classe& classe) {
    os << "Classe ID: " << classe.id << "\n";
    os << "Etudiants (" << classe.etudiants.size() << "):\n";
    for (const auto& etudiant : classe.etudiants) {
        os << "  " << etudiant << "\n";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Classe& classe) {
    std::string matricule, nom;
    int age, id;
    std::cout << "Matricule: ";
    is >> matricule;
    std::cout << "Nom: ";
    is >> nom;
    std::cout << "Age: ";
    is >> age;
    std::cout << "ID: ";
    is >> id;
    Etudiant etudiant(matricule, nom, age, id);
    classe.ajouterEtudiant(etudiant);
    return is;
}
