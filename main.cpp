#include <iostream>
#include <vector>
#include <string>
#include "jocdungeon.h"
#include "jucator.h"
#include "inamic.h"
#include "gamedata.h"
#include "inventar.h"
#include "pistoale.h"
#include "battlelog.h"
#include "radar.h"

int main() {
    std::cout << GameData::getPovesteFundal() << "\n";

    JocDungeon joc("Dungeon Final", 15, 10);
    joc.initSesiune();

    const Labirint& lab = joc.getLabirint();
    int linii = lab.getLinii();
    int coloane = lab.getColoane();
    std::cout << "Dimensiuni: " << linii << "x" << coloane << "\n";

    Jucator erou("Viteazul", Pozitie(1, 1));
    erou.setPozitie(Pozitie(2, 2));
    erou.adaugaXP(200);

    std::cout << "Nivel erou: " << erou.getNivel() << "\n";
    std::cout << "HP: " << erou.getHP() << " | XP: " << erou.getXP() << "/" << erou.getXPNecesar() << "\n";
    std::cout << GameData::getMesajLevelUp(erou.getNivel()) << "\n";

    std::vector<std::string> tipuri = GameData::getTipuriInamici();
    for(const auto& t : tipuri) {
        std::cout << "Inamic disponibil: " << GameData::getDescriereInamic(t) << "\n";
    }

    std::vector<Inamic*> inamici;
    Inamic* boss = new Inamic("Seful Goblins", Pozitie(2, 2), 50);
    inamici.push_back(boss);

    if (lab.estePozitieValida(2, 2)) {
        lab.afisareGrafica(erou.getPozitie(), inamici);
        boss->ataca(erou);
    }

    Inventar rucsac(5);
    Pistoale* gun = new Pistoale(25, 12);
    gun->reincarca();
    rucsac.adaugaObiect(gun);
    rucsac.afiseazaTot();
    rucsac.folosesteToate();

    std::string jurnal = BattleLog::genereazaDescriereLupta(erou.getNume(), boss->getNume(), 30);
    BattleLog::adaugaEveniment(jurnal);
    BattleLog::afiseazaLog();
    BattleLog::curataLog();

    joc.verificaInteractiune(erou, inamici);

    for (auto* i : inamici) delete i;
    inamici.clear();

    Radar miniMap(4);
    miniMap.afiseazaRadar(erou.getPozitie(), inamici);
    std::cout << miniMap.getDistantaPanaLaCelMaiApropiat(erou.getPozitie(), inamici) << "\n";

    return 0;

}