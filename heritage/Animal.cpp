//
// Created by youssoupha faye on 08/01/2026.
//

#include "Animal.hpp"

#include <iostream>
#include <ostream>

void Animal::bouger() {
    std::cout << "Animal bouger" << std::endl;
}
Animal::Animal(int poid) : Vivant(poid) {

}

