#ifndef ENTITATE_H
#define ENTITATE_H

#include <string>
#include "pozitie.h"

class Entitate {
protected:
    std::string nume;
    Pozitie pos;
    int hp;
    int hpMax;
    int atac;
    int aparare;

public:
    Entitate(std::string n, Pozitie p, int health, int atk, int def);
    virtual ~Entitate() = default;
    virtual void actioneaza() = 0;

    Pozitie getPozitie() const { return pos; }
    void setPozitie(Pozitie p) { pos = p; }
    std::string getNume() const { return nume; }

    int getHP() const { return hp; }
    int getAtac() const { return atac; }
    bool esteVie() const { return hp > 0; }
    void primesteDamage(int dmg);
};

#endif