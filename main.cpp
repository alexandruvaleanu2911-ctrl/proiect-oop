#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include "jocdungeon.h"
#include "jucator.h"
#include "inamic.h"
#include "gamedata.h"
#include "inventar.h"
#include "pistoale.h"
#include "battlelog.h"

// Structura pentru a simula un eveniment neprevazut
struct EvenimentDungeon {
    std::string descriere;
    int impactHP;
    int bonusXP;
};

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    std::uniform_int_distribution<> dmgDis(5, 15);

    JocDungeon joc("Dungeon of Shadows", 20, 20);
    Jucator erou("Viteazul", Pozitie(0, 0));
    std::vector<Inamic*> inamici;

    inamici.push_back(new Inamic("Paznicul Pragului", Pozitie(1, 2), 40));
    inamici.push_back(new Inamic("Spectra", Pozitie(5, 5), 60));
    inamici.push_back(new Inamic("Seful Final", Pozitie(10, 10), 120));

    BattleLog::adaugaEveniment("--- SIMULARE DINAMICA INCEPUTA ---");

    for (int camera = 1; camera <= 5; ++camera) {
        std::cout << "\n>>> EXPLORARE CAMERA " << camera << " <<<\n";


        int sansa = dis(gen);
        EvenimentDungeon ev;

        if (sansa < 30) {
            ev = {"Ai calcat intr-o capcana cu tepi!", -15, 5};
        } else if (sansa < 60) {
            ev = {"Ai gasit o licoare veche pe un piedestal.", 10, 10};
        } else {
            ev = {"Camera pare linistita, dar aerul este greu.", 0, 2};
        }

        erou.primesteDamage(-ev.impactHP);
        erou.adaugaXP(ev.bonusXP);
        BattleLog::adaugaEveniment("Eveniment: " + ev.descriere);

        if (camera % 2 == 0 && !inamici.empty()) {
            Inamic* tinta = inamici.front();

            while (tinta->getHP() > 0 && erou.getHP() > 0) {
                int atacErou = dmgDis(gen) + (erou.getNivel() * 2);
                tinta->primesteDamage(atacErou);
                BattleLog::adaugaEveniment(BattleLog::genereazaDescriereLupta(erou.getNume(), tinta->getNume(), atacErou));

                if (tinta->getHP() > 0) {
                    int atacInamic = (dmgDis(gen) / 2);
                    erou.primesteDamage(atacInamic);
                    BattleLog::adaugaEveniment(BattleLog::genereazaDescriereLupta(tinta->getNume(), erou.getNume(), atacInamic));
                }
            }

            if (erou.getHP() > 0) {
                std::cout << "Inamic invins: " << tinta->getNume() << "\n";
                erou.adaugaXP(50);
                delete tinta;
                inamici.erase(inamici.begin());
            }
        }
    }

    std::cout << "\n====================================\n";
    erou.afisare();
    BattleLog::afiseazaLog();
    std::cout << "====================================\n";

    for (auto* i : inamici) delete i;
    inamici.clear();

    return 0;
}