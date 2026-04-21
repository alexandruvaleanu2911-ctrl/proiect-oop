#include "inamic.h"
#include <iostream>

Inamic::Inamic(std::string n, Pozitie p, int health)
    : Entitate(n, p, health, 10, 2) {}

void Inamic::actioneaza() {
    std::cout << "Inamicul " << nume << " pazaeste zona la pozitia ("
              << pos.getX() << ", " << pos.getY() << ").\n";
}

void Inamic::afisare() const {
    std::cout << "[Inamic] Nume: " << nume
              << " | HP: " << hp
              << " | Atac: " << atac
              << " | Pozitie: (" << pos.getX() << "," << pos.getY() << ")\n";
}

// Daca ai nevoie de o metoda specifica pentru atacul inamicului
void Inamic::ataca(Entitate& tinta) {
    std::cout << nume << " ataca pe " << tinta.getNume() << "!\n";
    tinta.primesteDamage(atac);
}