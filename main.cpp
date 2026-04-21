#include <iostream>
#include <vector>
#include "jocdungeon.h"
#include "jucator.h"
#include "inamic.h"
#include "GameData.h"

int main() {
    std::cout << GameData::getPovesteFundal() << "\n";

    JocDungeon joc("Misiune 1", 10, 10);
    joc.initSesiune();

    Jucator erou("Erou", Pozitie(1, 1));
    erou.setPozitie(Pozitie(1, 1));
    erou.afisare();
    erou.adaugaXP(150);

    std::cout << GameData::getMesajLevelUp(erou.getNivel()) << "\n";

    std::vector<Inamic*> inamici;
    Inamic* goblin = new Inamic("Goblin", Pozitie(2, 2), 20);
    inamici.push_back(goblin);

    goblin->afisare();
    goblin->ataca(erou);

    if(joc.getLabirint().estePozitieValida(1,1)) {
        joc.getLabirint().afisareGrafica(erou.getPozitie(), inamici);
    }

    joc.verificaInteractiune(erou, inamici);

    for (auto* i : inamici) delete i;

    return 0;
}