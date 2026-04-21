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

int main() {
    // 1. Folosim GameData (Rezolva getPovesteFundal, getTipuriInamici)
    std::cout << GameData::getPovesteFundal() << "\n";
    auto tipuri = GameData::getTipuriInamici();
    if (!tipuri.empty()) {
        std::cout << "Primul tip inamic: " << GameData::getDescriereInamic(tipuri[0]) << "\n";
    }

    // 2. Initializare Joc (Rezolva initSesiune, getLabirint, getLinii, getColoane)
    JocDungeon joc("Dungeon Final", 10, 10);
    joc.initSesiune();
    const Labirint& lab = joc.getLabirint();
    std::cout << "Labirint generat: " << lab.getLinii() << "x" << lab.getColoane() << "\n";

    // 3. Jucator si Pozitie (Rezolva setPozitie, getXP, getXPNecesar, getMesajLevelUp)
    Jucator erou("Viteazul", Pozitie(0, 0));
    erou.setPozitie(Pozitie(1, 1));
    std::cout << "Status: " << erou.getXP() << "/" << erou.getXPNecesar() << "\n";
    std::cout << GameData::getMesajLevelUp(erou.getNivel()) << "\n";

    // 4. Inventar si Obiecte (Rezolva adaugaObiect, reincarca, afiseazaTot, folosesteToate)
    Inventar rucsac(5);
    Pistoale* gun = new Pistoale(20, 12);
    gun->reincarca();
    rucsac.adaugaObiect(gun);
    rucsac.afiseazaTot();
    rucsac.folosesteToate();

    // 5. Inamici si Lupta (Rezolva ataca, afisareGrafica, estePozitieValida, verificaInteractiune)
    std::vector<Inamic*> inamici;
    Inamic* boss = new Inamic("Seful Goblins", Pozitie(2, 2), 50);
    inamici.push_back(boss);

    if (lab.estePozitieValida(2, 2)) {
        lab.afisareGrafica(erou.getPozitie(), inamici);
    }

    // Simulam atacul
    boss->ataca(erou);
    joc.verificaInteractiune(erou, inamici);

    // 6. BattleLog (Rezolva curataLog)
    BattleLog::adaugaEveniment("Simulare terminata.");
    BattleLog::afiseazaLog();
    BattleLog::curataLog();

    // Cleanup
    for (auto* i : inamici) delete i;
    inamici.clear();

    return 0;
}