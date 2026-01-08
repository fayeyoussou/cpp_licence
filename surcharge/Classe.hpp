//
// Created by youssoupha faye on 06/01/2026.
//

#pragma once
#include <vector>
#include <ostream>
#include <istream>

#include "Etudiant.hpp"


class Classe {
private:
    int id;
    std::vector<Etudiant> etudiants;

public:
    Classe(int id, std::vector<Etudiant> etudiants);
    Classe(int id);
    int getId();
    void setId(int id);
    std::vector<Etudiant>& getEtudiants();
    const std::vector<Etudiant>& getEtudiants() const;
    void ajouterEtudiant(const Etudiant& etudiant);
    boool operator[](std::string matricule);


    Classe& operator+=(const Etudiant& etudiant);
    Classe& operator-=(const std::string& matricule);


    Classe operator+(const Classe& other) const;
    Classe operator-(const Classe& other) const;


    Classe& operator=(const Classe& other);
    bool operator==(const Classe& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Classe& classe);
    friend std::istream& operator>>(std::istream& is, Classe& classe);

};
