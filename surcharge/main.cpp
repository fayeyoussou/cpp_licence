#include <iostream>
#include "Classe.hpp"
#include "Etudiant.hpp"

void printSeparator(const std::string& title) {
    std::cout << "\n========== " << title << " ==========\n";
}

int main() {
    printSeparator("ETUDIANT CLASS TESTS");

    std::cout << "\n--- Test 1: Creating Etudiants ---\n";
    Etudiant e1("MAT001", "Awa CISSE", 20, 1);
    Etudiant e2("MAT002", "Abdoulaye DIOCKOU", 21, 2);
    Etudiant e3("MAT003", "Papa Amadou KANE", 19, 3);

    std::cout << "Compteur d'etudiants: " << Etudiant::getCompteur() << std::endl;

    std::cout << "\n--- Test 2: Adding notes and moyenne ---\n";
    e1.addNote(15.5);
    e1.addNote(17.0);
    e1.addNote(16.5);
    std::cout << "Notes de " << e1.getNom() << ": ";
    for (double note : e1.getNotes()) {
        std::cout << note << " ";
    }
    std::cout << "\nMoyenne: " << e1.moyenne() << std::endl;

    e2.addNote(18.0);
    e2.addNote(19.5);
    e2.addNote(17.5);
    std::cout << "\nNotes de " << e2.getNom() << ": ";
    for (double note : e2.getNotes()) {
        std::cout << note << " ";
    }
    std::cout << "\nMoyenne: " << e2.moyenne() << std::endl;

    e3.addNote(14.0);
    e3.addNote(13.5);
    e3.addNote(15.0);
    std::cout << "\nNotes de " << e3.getNom() << ": ";
    for (double note : e3.getNotes()) {
        std::cout << note << " ";
    }
    std::cout << "\nMoyenne: " << e3.moyenne() << std::endl;

    std::cout << "\n--- Test 3: operator<< for Etudiant ---\n";
    std::cout << e1 << std::endl;
    std::cout << e2 << std::endl;
    std::cout << e3 << std::endl;

    std::cout << "\n--- Test 4: operator== for Etudiant ---\n";
    Etudiant e4("MAT001", "Duplicate", 22, 4);
    std::cout << "e1 == e4? " << (e1 == e4 ? "Oui (meme matricule)" : "Non") << std::endl;
    std::cout << "e1 == e2? " << (e1 == e2 ? "Oui" : "Non (matricules differents)") << std::endl;

    std::cout << "\n--- Test 5: operator> and operator< for Etudiant ---\n";
    std::cout << e2.getNom() << " (moyenne: " << e2.moyenne() << ") > "
              << e1.getNom() << " (moyenne: " << e1.moyenne() << ")? "
              << (e2 > e1 ? "Oui" : "Non") << std::endl;
    std::cout << e3.getNom() << " (moyenne: " << e3.moyenne() << ") < "
              << e1.getNom() << " (moyenne: " << e1.moyenne() << ")? "
              << (e3 < e1 ? "Oui" : "Non") << std::endl;

    printSeparator("CLASSE CLASS TESTS");

    std::cout << "\n--- Test 6: Creating Classes ---\n";
    Classe classe1(101);
    Classe classe2(102);
    std::cout << "Classe1 ID: " << classe1.getId() << std::endl;
    std::cout << "Classe2 ID: " << classe2.getId() << std::endl;

    std::cout << "\n--- Test 7: operator+= to add Etudiant to Classe ---\n";
    classe1 += e1;
    classe1 += e2;
    std::cout << "Classe1 apres ajout de 2 etudiants:\n";
    std::cout << classe1 << std::endl;

    classe2 += e2;
    classe2 += e3;
    std::cout << "Classe2 apres ajout de 2 etudiants:\n";
    std::cout << classe2 << std::endl;

    std::cout << "\n--- Test 8: operator[] to find Etudiant by matricule ---\n";
    Etudiant* found = classe1["MAT001"];
    if (found) {
        std::cout << "Etudiant trouve: " << *found << std::endl;
    } else {
        std::cout << "Etudiant non trouve" << std::endl;
    }

    Etudiant* notFound = classe1["MAT999"];
    if (notFound) {
        std::cout << "Etudiant trouve: " << *notFound << std::endl;
    } else {
        std::cout << "MAT999 non trouve dans classe1" << std::endl;
    }

    std::cout << "\n--- Test 9: operator+ to merge classes ---\n";
    Classe classe3 = classe1 + classe2;
    std::cout << "Classe3 (classe1 + classe2):\n";
    std::cout << classe3 << std::endl;

    std::cout << "\n--- Test 10: operator- to subtract classes ---\n";
    Classe classe4 = classe1 - classe2;
    std::cout << "Classe4 (classe1 - classe2 - retire les etudiants communs):\n";
    std::cout << classe4 << std::endl;

    std::cout << "\n--- Test 11: operator-= to remove Etudiant by matricule ---\n";
    std::cout << "Avant suppression:\n" << classe1 << std::endl;
    classe1 -= "MAT002";
    std::cout << "Apres suppression de MAT002:\n" << classe1 << std::endl;

    std::cout << "\n--- Test 12: operator= to copy classe ---\n";
    Classe classe5(999);
    classe5 = classe2;
    std::cout << "Classe5 apres copie de classe2:\n";
    std::cout << classe5 << std::endl;
    std::cout << "ID de classe5: " << classe5.getId() << " (copie depuis classe2)" << std::endl;

    std::cout << "\n--- Test 13: operator== to compare classes ---\n";
    std::cout << "classe2 == classe5? " << (classe2 == classe5 ? "Oui (meme ID)" : "Non") << std::endl;
    std::cout << "classe1 == classe2? " << (classe1 == classe2 ? "Oui" : "Non (IDs differents)") << std::endl;

    std::cout << "\n--- Test 14: operator<< for Classe ---\n";
    std::cout << "Affichage final de classe2:\n";
    std::cout << classe2 << std::endl;

    printSeparator("FIN DES TESTS");
    std::cout << "\nCompteur final d'etudiants: " << Etudiant::getCompteur() << std::endl;
    std::cin >> e1;
    return 0;
}
