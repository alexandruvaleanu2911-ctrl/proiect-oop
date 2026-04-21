#include "battlelog.h"
#include <iostream>

std::vector<std::string> BattleLog::istoricEvenimente;

void BattleLog::adaugaEveniment(const std::string& eveniment) {
    istoricEvenimente.push_back(eveniment);
}

void BattleLog::curataLog() {
    istoricEvenimente.clear();
}

void BattleLog::afiseazaLog() {
    std::cout << "\n--- LOG DE LUPTA ---\n";
    for (const auto& ev : istoricEvenimente) {
        std::cout << ">> " << ev << "\n";
    }
}

std::string BattleLog::genereazaDescriereLupta(const std::string& numeJucator, const std::string& numeInamic, int damage) {
    if (damage > 15) 
        return numeJucator + " a distrus defensiva lui " + numeInamic + " cu " + std::to_string(damage) + " dmg!";
    if (damage > 0)
        return numeJucator + " a lovit pe " + numeInamic + " provocand " + std::to_string(damage) + " dmg.";
    return numeInamic + " a evitat cu succes atacul lansat de " + numeJucator + ".";
}