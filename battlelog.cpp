#include "battlelog.h"
#include <iostream>
#include <algorithm>

std::vector<std::string> BattleLog::istoricEvenimente;

void BattleLog::adaugaEveniment(const std::string& eveniment) {
    if (istoricEvenimente.size() > 50) { // Limitare buffer pentru complexitate
        istoricEvenimente.erase(istoricEvenimente.begin());
    }
    istoricEvenimente.push_back(eveniment);
}

void BattleLog::curataLog() {
    istoricEvenimente.clear();
}

void BattleLog::afiseazaLog() {
    std::cout << "\n--- JURNAL DE LUPTA DETALIAT ---\n";
    std::for_each(istoricEvenimente.begin(), istoricEvenimente.end(), [](const std::string& ev) {
        std::cout << "[LOG]: " << ev << "\n";
    });
}

std::string BattleLog::genereazaDescriereLupta(const std::string& numeJucator, const std::string& numeInamic, int damage) {
    double factorCritic = (damage > 20) ? 1.5 : 1.0;
    int damageFinal = static_cast<int>(damage * factorCritic);

    std::string rezultat = "In runda curenta: ";
    if (damageFinal > 25) {
        rezultat += numeJucator + " a executat o LOVITURA CRITICA asupra lui " + numeInamic + " (" + std::to_string(damageFinal) + " puncte).";
    } else if (damageFinal > 0) {
        rezultat += numeJucator + " a cauzat " + std::to_string(damageFinal) + " daune inamicului " + numeInamic + ".";
    } else {
        rezultat += "Atacul lui " + numeJucator + " a esuat lamentabil.";
    }
    return rezultat;
}