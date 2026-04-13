#ifndef ENTITATE_H
#define ENTITATE_H

#include <string>
#include "pozitie.h"

class Entitate {
protected:
    std::string nume;
    Pozitie pos;
    int viata;

public:
    Entitate(std::string  n, Pozitie p, int v);
    virtual ~Entitate() = default;
    virtual void actioneaza() = 0;
    
    virtual void afisare() const;

    Pozitie getPozitie() const { return pos; }
    void setPozitie(const Pozitie& p) { pos = p; }
};

#endif