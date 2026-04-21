#ifndef JUCATOR_H
#define JUCATOR_H

#include "entitate.h"

class Jucator : public Entitate {
    int nivel;
    int xpCurent;
    int xpNecesar;

public:
    Jucator(std::string n, Pozitie p);
    void actioneaza() override;
    void adaugaXP(int xp);
    void crescInNivel();

    int getNivel() const { return nivel; }
    int getXP() const { return xpCurent; }
    int getXPNecesar() const { return xpNecesar; }
};

#endif