#include "inamic.h"
#include <iostream>
#include <utility>

Inamic::Inamic(const std::string& n, Pozitie p, int atac)
    : Entitate(n, p, 50), puncteAtac(atac) {}

void Inamic::actioneaza() {
    std::cout << "[Inamic] " << nume << " te ataca cu o putere de " << puncteAtac << "!\n";
}

void Inamic::afisare() const {
    std::cout << "XXX INAMIC: " << nume << " | Atac: " << puncteAtac << "\n";
}