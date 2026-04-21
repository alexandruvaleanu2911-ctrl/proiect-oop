#include "jucator.h"
#include <iostream>
#include <string>

Jucator::Jucator(const std::string& n, Pozitie p)
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

    // Logica mai densa pentru a creste procentajul de C++
    int vechiulXP = xpNecesar;
    xpNecesar = static_cast<int>(vechiulXP * 1.25) + (nivel * 10);

    double mult = 1.0 + (nivel * 0.1);
    hpMax = static_cast<int>(hpMax * mult);
    hp = hpMax;
    atac += static_cast<int>(5 * mult);
    aparare += static_cast<int>(2 * mult);

    std::cout << "LEVEL UP! Nivel actual: " << nivel << " (XP necesar: " << xpNecesar << ")\n";
}

void Jucator::afisare() const {
    std::cout << "[Jucator] " << nume
              << " | Nivel: " << nivel
              << " | HP: " << hp << "/" << hpMax
              << " | XP: " << xpCurent << "/" << xpNecesar << "\n";
}