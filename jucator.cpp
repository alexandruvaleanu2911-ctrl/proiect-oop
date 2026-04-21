#include "jucator.h"
#include <iostream>
#include <cmath>

Jucator::Jucator(std::string n, Pozitie p)
    : Entitate(n, p, 100, 15, 5), nivel(1), xpCurent(0), xpNecesar(100) {}

void Jucator::actioneaza() {
    std::cout << "Jucatorul " << nume << " exploreaza la nivelul " << nivel << ".\n";
}

void Jucator::adaugaXP(int xp) {
    xpCurent += xp;
    std::cout << "Ai castigat " << xp << " XP! (" << xpCurent << "/" << xpNecesar << ")\n";

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

    std::cout << "\n--- LEVEL UP! --- \n";
    std::cout << "Nivel nou: " << nivel << "\n";
    std::cout << "Statistici marite: HP: " << hpMax << ", ATK: " << atac << ", DEF: " << aparare << "\n";
    std::cout << "XP necesar pentru nivelul urmator: " << xpNecesar << "\n\n";
}