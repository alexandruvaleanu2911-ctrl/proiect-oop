#include <iostream>
#include <vector>
#include "jocdungeon.h"
#include "jucator.h"
#include "inamic.h"
#include "gamedata.h"
#include "inventar.h"
#include "pistoale.h"

int main() {
    std::cout << GameData::getPovesteFundal() << "\n";
    std::cout << "Tipuri: " << GameData::getTipuriInamici().size() << "\n";
    std::cout << GameData::getDescriereInamic("Goblin") << "\n";

    JocDungeon joc("Test", 10, 10);
    joc.initSesiune();

    Jucator erou("Erou", Pozitie(1, 1));
    erou.setPozitie(Pozitie(1, 1));
    erou.afisare();
    erou.adaugaXP(150);

    std::cout << "Statistici: HP " << erou.getHP() << ", XP " << erou.getXP() << "/" << erou.getXPNecesar() << "\n";
    std::cout << "Mesaj: " << GameData::getMesajLevelUp(erou.getNivel()) << "\n";

    std::cout << "Labirint: " << joc.getLabirint().getLinii() << "x" << joc.getLabirint().getColoane() << "\n";

    Inventar rucsac(5);
    Pistoale* p = new Pistoale(20, 12);
    p->reincarca();
    rucsac.adaugaObiect(p);
    rucsac.afiseazaTot();
    rucsac.folosesteToate();

    std::vector<Inamic*> inamici;
    Inamic* goblin = new Inamic("Goblin", Pozitie(2, 2), 20);
    inamici.push_back(goblin);

    goblin->afisare();
    goblin->ataca(erou);

    if(joc.getLabirint().estePozitieValida(1, 1)) {
        joc.getLabirint().afisareGrafica(erou.getPozitie(), inamici);
    }

    joc.verificaInteractiune(erou, inamici);

    for (auto* i : inamici) delete i;

    return 0;
}