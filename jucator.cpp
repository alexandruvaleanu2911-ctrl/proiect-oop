#include "jucator.h"
#include <iostream>

Jucator::Jucator(std::string n, Pozitie p)
    : Entitate(n, p, 100, 15, 5), nivel(1), xpCurent(0), xpNecesar(100) {}

void Jucator::actioneaza() {
    std::cout << "Jucatorul " << nume << " exploreaza nivelul " << nivel << ".\n";
}

void Jucator::adaugaXP(int xp) {
    xpCurent += xp;
    while (xpCurent >= xpNecesar) {
        crescInNivel();
    }
}

void Jucator::crescInNivel() {
    xpCurent -= xpNecesar;
    nivel++;
    xpNecesar = static_cast<int>(xpNecesar * 1.2);
    hpMax += 20;
    hp = hpMax;
    atac += 5;
    aparare += 2;
    std::cout << "LEVEL UP! Nivel: " << nivel << "\n";
}

void Jucator::afisare() const {
    std::cout << "[Jucator] " << nume
              << " | Nivel: " << nivel
              << " | HP: " << hp << "/" << hpMax
              << " | XP: " << xpCurent << "/" << xpNecesar << "\n";
}