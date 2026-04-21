#include <iostream>
#include <vector>
#include "jocdungeon.h"
#include "jucator.h"
#include "inamic.h"
#include "gamedata.h"
#include "inventar.h"
#include "pistoale.h"
#include "battlelog.h"

int main() {
    std::cout << GameData::getPovesteFundal() << "\n";
    
    BattleLog::adaugaEveniment("Sesiune noua inceputa.");
    std::string descriere = BattleLog::genereazaDescriereLupta("Erou", "Goblin", 25);
    BattleLog::adaugaEveniment(descriere);
    BattleLog::afiseazaLog();
    BattleLog::curataLog();

    JocDungeon joc("Dungeon Test", 10, 10);
    joc.initSesiune();

    Jucator erou("Erou", Pozitie(1, 1));


    erou.setPozitie(Pozitie(2, 2));

    erou.afisare();
    erou.adaugaXP(150);


    std::cout << "Statistici: HP " << erou.getHP() << ", XP " << erou.getXP() << "/" << erou.getXPNecesar() << "\n";

    std::cout << "Mesaj: " << GameData::getMesajLevelUp(erou.getNivel()) << "\n";
    std::cout << "Descriere inamic: " << GameData::getDescriereInamic("Orc") << "\n";
    std::cout << "Tipuri: " << GameData::getTipuriInamici().size() << "\n";

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