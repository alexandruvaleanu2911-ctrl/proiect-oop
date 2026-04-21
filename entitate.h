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
    virtual void afisare() const = 0;

    Pozitie getPozitie() const { return pos; }
    void setPozitie(Pozitie p) { pos = p; }
    std::string const& getNume() const { return nume; }
    int getHP() const { return hp; }
    void primesteDamage(int dmg);
};

#endif