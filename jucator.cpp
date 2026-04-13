#include "jucator.h"
#include <iostream>

Jucator::Jucator(std::string n, Pozitie p) 
    : Entitate(std::move(n), p, 100), nivel(1), experienta(0) {}

void Jucator::actioneaza() {
    std::cout << "[Jucator] " << nume << " cauta comori in labirint...\n";
}

void Jucator::afisare() const {
    std::cout << ">>> JUCATOR: " << nume << " | LVL: " << nivel 
              << " | XP: " << experienta << "/100 | Poz: " << pos << "\n";
}

void Jucator::adaugaXP(int xp) {
    experienta += xp;
    if (experienta >= 100) {
        nivel++;
        experienta -= 100;
        std::cout << "!!! LEVEL UP !!! Acum ai nivelul " << nivel << "\n";
    }
}