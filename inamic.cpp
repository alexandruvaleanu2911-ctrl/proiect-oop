#include "inamic.h"
#include <iostream>

Inamic::Inamic(std::string n, Pozitie p, int atac) 
    : Entitate(std::move(n), p, 50), putereAtac(atac) {}

void Inamic::actioneaza() {
    std::cout << "[Inamic] " << nume << " te ataca cu o putere de " << putereAtac << "!\n";
}

void Inamic::afisare() const {
    std::cout << "XXX INAMIC: " << nume << " | Atac: " << putereAtac 
              << " | HP: " << viata << " | Poz: " << pos << "\n";
}