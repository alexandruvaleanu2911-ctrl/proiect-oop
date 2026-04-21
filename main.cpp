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

    if (dim < 6) dim = 10;

    JocDungeon joculMeu(nume, dim, dim);
    joculMeu.initSesiune();

    Jucator erou(nume, Pozitie(1, 1));

    std::vector<Inamic*> listaInamici;
    listaInamici.push_back(new Inamic("Goblin", Pozitie(2, 2), 15));
    listaInamici.push_back(new Inamic("Orc", Pozitie(dim - 2, dim - 2), 30));
    listaInamici.push_back(new Inamic("Skeleton", Pozitie(1, dim - 3), 10));

    std::cout << "\n--- VIZUALIZARE HARTA ---" << std::endl;
    joculMeu.getLabirint().afisareGrafica(erou.getPozitie(), listaInamici);

    std::cout << "\n--- GESTIONARE ECHIPAMENT ---" << std::endl;
    Inventar* rucsac = new Inventar(5);
    rucsac->adaugaObiect(new Sabie(50, 25));
    rucsac->adaugaObiect(new Spear(75, 35));
    rucsac->afiseazaTot();

    for (auto* inamic : listaInamici) {
        delete inamic;
    }
    delete rucsac;

    std::cout << "\n--- AVENTURA S-A INCHEIAT ---" << std::endl;
    return 0;
}