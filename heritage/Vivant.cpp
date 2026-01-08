//
// Created by youssoupha faye on 08/01/2026.
//

#include "Vivant.hpp"

#include <iostream>
#include <ostream>

Vivant::Vivant(int poid) {

}

void Vivant::bouger() {
    std::cout << "Vivant bouge" << std::endl;
}
int Vivant::getPoid() const {
    return poid;
}
void Vivant::setPoid(int poid) {
    this->poid = poid;
}


