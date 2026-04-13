#include <iostream>
#include <string>
#include "jocdungeon.h"

int main() {
    std::string nume;
    int dim;

    std::cout << "Introduceti numele si dimensiunea: ";
    if (!(std::cin >> nume >> dim)) return 0;

    JocDungeon joculMeu(nume, dim, dim);
    joculMeu.initSesiune();

    JocDungeon copieJoc = joculMeu;
    std::cout << copieJoc;

    return 0;
}