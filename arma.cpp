#include "arma.h"

Arma::Arma(std::string n, int v, int d) : Obiect(n, v), damage(d) {}

void Arma::afisare() const {
    Obiect::afisare();
    std::cout << " [Damage: " << damage << "]";
}