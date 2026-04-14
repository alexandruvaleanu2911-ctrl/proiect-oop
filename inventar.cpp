#include "inventar.h"
#include <iostream>

Inventar::Inventar(int cap) : capacitateMaxima(cap) {
    iteme.reserve(cap);
}

Inventar::~Inventar() {
    for (Obiect* obj : iteme) {
        delete obj; 
    }
    iteme.clear();
    std::cout << "[Debug] Inventarul a fost curatat din memorie.\n";
}

bool Inventar::adaugaObiect(Obiect* obj) {
    if (obj == nullptr) return false;

    if (iteme.size() < (size_t)capacitateMaxima) {
        iteme.push_back(obj);
        std::cout << "Obiectul " << obj->getNume() << " a fost adaugat in inventar.\n";
        return true;
    }

    std::cout << "Inventar plin! Nu s-a putut adauga: " << obj->getNume() << "\n";
    return false;
}

void Inventar::afiseazaTot() const {
    std::cout << "--- CONTINUT INVENTAR (" << iteme.size() << "/" << capacitateMaxima << ") ---\n";
    if (iteme.empty()) {
        std::cout << "Inventarul este gol.\n";
        return;
    }
    for (const auto* obj : iteme) {
        obj->afisare();
    }
    std::cout << "------------------------------------------\n";
}

void Inventar::folosesteToate() {
    std::cout << "Se folosesc toate obiectele din inventar...\n";
    for (auto* obj : iteme) {
        obj->foloseste();
    }
}