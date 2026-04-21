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
    // 1. GameData & Intro
    std::cout << GameData::getPovesteFundal() << "\n";

    // 2. Initializare Jucator
    Jucator erou("Viteazul", Pozitie(1, 1));
    erou.setPozitie(Pozitie(2, 2));

    // REPARARE: getHP (afisam HP-ul eroului)
    std::cout << "HP Initial: " << erou.getHP() << "\n";

    // REPARARE: adaugaXP (apelam metoda)
    erou.adaugaXP(150);
    std::cout << "XP: " << erou.getXP() << "/" << erou.getXPNecesar() << "\n";

    // 3. BattleLog & Lupta
    // REPARARE: genereazaDescriereLupta (trebuie sa salvam/afisam rezultatul)
    std::string jurnal = BattleLog::genereazaDescriereLupta(erou.getNume(), "Goblin", 30);
    BattleLog::adaugaEveniment(jurnal);
    std::cout << "Ultimul eveniment: " << jurnal << "\n";

    // 4. Joc & Labirint
    JocDungeon joc("Test", 10, 10);
    joc.initSesiune();
    const Labirint& lab = joc.getLabirint();

    if (lab.estePozitieValida(2, 2)) {
        std::vector<Inamic*> inamici;
        Inamic* g = new Inamic("Goblin", Pozitie(2, 2), 20);
        inamici.push_back(g);

        lab.afisareGrafica(erou.getPozitie(), inamici);
        joc.verificaInteractiune(erou, inamici);

        delete g;
    }

    // 5. Inventar
    Inventar inv(5);
    Pistoale* p = new Pistoale(10, 6);
    p->reincarca();
    inv.adaugaObiect(p);
    inv.afiseazaTot();
    inv.folosesteToate();

    // 6. Finalizare
    BattleLog::afiseazaLog();
    BattleLog::curataLog();

    return 0;
}