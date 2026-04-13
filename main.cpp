#include <iostream>
#include <string>
#include "jocdungeon.h"
#include "jucator.h"
#include "inamic.h"

int main() {
    std::string nume;
    int dim;

    std::cout << "Introduceti numele si dimensiunea: ";
    if (!(std::cin >> nume >> dim)) return 0;

    JocDungeon joculMeu(nume, dim, dim);
    joculMeu.initSesiune();

    Jucator erou(nume, Pozitie(1, 1));
    Inamic monstru("Goblin", Pozitie(2, 2), 15);

    erou.afisare();
    erou.adaugaXP(120);

    monstru.afisare();

    Pozitie p = monstru.getPozitie();
    erou.setPozitie(p);
    // ---------------------------------------------

    JocDungeon copieJoc = joculMeu;
    std::cout << copieJoc;

    return 0;
}