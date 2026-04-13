#ifndef JUCATOR_H
#define JUCATOR_H

#include "entitate.h"
#include "pozitie.h"
#include <string>

class Jucator : public Entitate {
private:
    int nivel;
    int experienta;

public:
    // Constructorul - asigura-te ca Pozitie e scris cu P mare daca asa e clasa
    Jucator(std::string n, Pozitie p);

    void actioneaza() override;
    void afisare() const override;
    void adaugaXP(int xp);
};

#endif