#include <iostream>
#include <string>
#include <vector>
#include "jocdungeon.h"
#include "jucator.h"
#include "inamic.h"
#include "inventar.h"
#include "sabie.h"
#include "spear.h"
#include "pistoale.h"
#include "potiune.h"

int main() {
    std::string nume;
    int dim;

    std::cout << "--- BINE AI VENIT IN DUNGEON ---" << std::endl;
    std::cout << "Introduceti numele eroului si dimensiunea lumii: ";
    if (!(std::cin >> nume >> dim)) return 0;

    JocDungeon joculMeu(nume, dim, dim);
    joculMeu.initSesiune();

    Jucator erou(nume, Pozitie(1, 1));
    Inamic monstru("Goblin Scout", Pozitie(2, 2), 15);

    std::cout << "\n--- STATUS INITIAL ---" << std::endl;
    erou.afisare();
    monstru.afisare();

    std::cout << "\n--- GESTIONARE ECHIPAMENT ---" << std::endl;
    Inventar* rucsac = new Inventar(5);

    rucsac->adaugaObiect(new Sabie(50, 25));
    rucsac->adaugaObiect(new Spear(75, 35));
    rucsac->adaugaObiect(new Pistoale(120, 45, 6));
    rucsac->adaugaObiect(new Potiune("Licoare Magica", 30, 40));

    rucsac->afiseazaTot();

    std::cout << "\n--- SIMULARE LUPTA ---" << std::endl;
    erou.actioneaza();
    rucsac->folosesteToate();

    monstru.actioneaza();

    erou.adaugaXP(150);
    erou.setPozitie(monstru.getPozitie());

    std::cout << "\n--- TEST REINCARCARE ---" << std::endl;
    Pistoale* deTest = new Pistoale(100, 40, 0);
    deTest->reincarca();
    deTest->foloseste();
    delete deTest;

    std::cout << "\n--- TEST COPIERE JOC ---" << std::endl;
    JocDungeon copieJoc = joculMeu;

    delete rucsac;

    std::cout << "\n--- AVENTURA S-A INCHEIAT ---" << std::endl;
    return 0;
}