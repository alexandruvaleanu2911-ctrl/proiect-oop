#include "entitate.h"
#include <iostream>
#include <utility>

Entitate::Entitate(const std::string& n, Pozitie p, int v) : nume(n), pos(p), viata(v) {}

void Entitate::afisare() const {
    std::cout << nume << " se afla la " << pos << " HP: " << viata;
}