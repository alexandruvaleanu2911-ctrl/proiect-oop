#include "inamic.h"
#include <iostream>

Inamic::Inamic(const std::string& n, Pozitie p, int health)
    : Entitate(n, p, health, 10, 2) {}

void Inamic::actioneaza() {
    std::cout << "Inamicul " << nume << " pandeste la (" << pos.getX() << "," << pos.getY() << ").\n";
}

void Inamic::afisare() const {
    std::cout << "[Inamic] " << nume << " | HP: " << hp << "\n";
}

void Inamic::ataca(Entitate& tinta) {
    std::cout << nume << " ataca pe " << tinta.getNume() << "!\n";
    tinta.primesteDamage(10);
}