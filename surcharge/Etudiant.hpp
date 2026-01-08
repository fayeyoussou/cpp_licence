//
// Created by youssoupha faye on 06/01/2026.
//

#pragma once
#include <string>
#include <ostream>
#include <vector>

class Etudiant {
    static int compteur;
    std::string matricule;
    std::string nom;
    int age;
    int id;
    std::vector<double> notes;
public:

    Etudiant(std::string matricule, std::string nom,
    int age,int id = 0);
    ~Etudiant() = default;
    static int getCompteur();
    std::string getMatricule() const;
    std::string getNom() const;
    int getAge() const;
    int getId() const;
    void setMatricule(const std::string& matricule);
    void setNom(const std::string& nom);
    void setAge(const int age);
    void setId(const int id);

    std::vector<double>& getNotes();
    const std::vector<double>& getNotes() const;
    void addNote(double note);
    double moyenne() const;

    friend std::ostream& operator<<(std::ostream& os, const Etudiant& e);
    friend std::istream& operator>>(std::istream& is, Etudiant& e);
    void afficherPersonne() const;
    friend bool operator==(const Etudiant& a, const Etudiant& b);
    friend bool operator>(const Etudiant& a, const Etudiant& b);
    friend bool operator<(const Etudiant& a, const Etudiant& b);

};
