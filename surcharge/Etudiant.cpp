//
// Created by youssoupha faye on 06/01/2026.
//

#include "Etudiant.hpp"
#include <iostream>
// STATIC
int Etudiant::compteur = 0;
int Etudiant::getCompteur() {
    return compteur;
}
// CONSTRUCTOR
Etudiant::Etudiant(std::string matricule, std::string nom, int age,int id) : matricule(matricule), nom(nom), age(age), id(id){
    compteur ++;
}



// GETTER

std::string Etudiant::getNom() const {
    return nom;
}

int Etudiant::getAge() const {
    return age;
}

int Etudiant::getId() const {
    return id;
}

std::string Etudiant::getMatricule() const {
    return matricule;
}

void Etudiant::afficherPersonne() const {
    std::cout << this->getNom();
}

// SETTER

void Etudiant::setNom(const std::string& nom) {
    this->nom = nom;
}

void Etudiant::setAge(const int age) {
    this->age = age;
}

void Etudiant::setId(const int id) {
    this->id = id;
}

void Etudiant::setMatricule(const std::string &matricule) {
    this->matricule = matricule;
}

std::vector<double>& Etudiant::getNotes() {
    return notes;
}

const std::vector<double>& Etudiant::getNotes() const {
    return notes;
}

void Etudiant::addNote(double note) {
    notes.push_back(note);
}

double Etudiant::moyenne() const {
    if (notes.empty()) {
        return 0.0;
    }
    double sum = 0.0;
    for (double note : notes) {
        sum += note;
    }
    return sum / notes.size();
}

// SURCHARGE
std::ostream& operator<<(std::ostream& os, const Etudiant& e)  {
    os << "Matricule: " << e.matricule << ", Nom: " << e.nom << ", Age: " << e.age << ", Moyenne: " << e.moyenne();
    return os;
}

std::istream& operator>>(std::istream& is, Etudiant& e) {
    std::cout << "Matricule: ";
    is >> e.matricule;
    std::cout << "Nom: ";
    is >> e.nom;
    std::cout << "Age: ";
    is >> e.age;
    std::cout << "ID: ";
    is >> e.id;
    return is;
}

bool operator==(const Etudiant& a, const Etudiant& b) {
    return a.matricule == b.matricule;
}

bool operator>(const Etudiant& a, const Etudiant& b) {
    return a.age > b.age;
}

bool operator<(const Etudiant& a, const Etudiant& b) {
    return a.age < b.age;
}
