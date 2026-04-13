#include "entitate.h"
#include <iostream>

Entitate::Entitate(std::string n, Pozitie p, int v) : nume(std::move(n)), pos(p), viata(v) {}

void Entitate::afisare() const {
    std::cout << nume << " se afla la " << pos << " HP: " << viata;
}