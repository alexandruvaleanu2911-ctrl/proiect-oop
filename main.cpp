#include <iostream>
#include <string>
#include <vector>
#include "jocdungeon.h"
#include "jucator.h"
#include "inamic.h"
#include "inventar.h"
#include "pistoale.h"

int main() {
    std::string nume = "Erou";
    JocDungeon joculMeu(nume, 10, 10);
    joculMeu.initSesiune();

    Jucator erou(nume, Pozitie(1, 1));
    erou.adaugaXP(50);
    erou.setPozitie(Pozitie(1, 1));

    if (joculMeu.getLabirint().estePozitieValida(1, 1)) {
        std::cout << "Pozitie confirmata de Labirint.\n";
    }

    std::vector<Inamic*> listaInamici;
    listaInamici.push_back(new Inamic("Goblin", Pozitie(2, 2), 15));

    int l = joculMeu.getLabirint().getLinii();
    int c = joculMeu.getLabirint().getColoane();
    std::cout << "Dimensiuni: " << l << "x" << c << "\n";

    joculMeu.getLabirint().afisareGrafica(erou.getPozitie(), listaInamici);

    Inventar* rucsac = new Inventar(5);
    Pistoale* p = new Pistoale(20, 12);
    p->reincarca();
    rucsac->adaugaObiect(p);
    rucsac->folosesteToate();

    joculMeu.verificaInteractiune(erou, listaInamici);

    for (auto* i : listaInamici) delete i;
    delete rucsac;

    return 0;
}