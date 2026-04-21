#include <iostream>
#include <string>
#include <vector>
#include "jocdungeon.h"
#include "jucator.h"
#include "inamic.h"
#include "inventar.h"
#include "sabie.h"
#include "pistoale.h"

int main() {
    std::string nume = "Erou";
    int dim = 10;

    JocDungeon joculMeu(nume, dim, dim);
    joculMeu.initSesiune();

    Jucator erou(nume, Pozitie(1, 1));
    erou.adaugaXP(50);

    std::vector<Inamic*> listaInamici;
    listaInamici.push_back(new Inamic("Goblin", Pozitie(2, 2), 15));

    if (joculMeu.getLabirint().estePozitieValida(1, 1)) {
        joculMeu.getLabirint().afisareGrafica(erou.getPozitie(), listaInamici);
    }

    Inventar* rucsac = new Inventar(5);
    Pistoale* p = new Pistoale(20, 12);
    p->reincarca();
    rucsac->adaugaObiect(p);
    rucsac->afiseazaTot();
    rucsac->folosesteToate();

    joculMeu.verificaInteractiune(erou, listaInamici);

    for (auto* i : listaInamici) delete i;
    delete rucsac;

    return 0;
}