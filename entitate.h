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
    Entitate(const std::string& n, Pozitie p, int v);
    virtual ~Entitate() = default;
    virtual void actioneaza() = 0;
    virtual void afisare() const;

    std::string getNume() const { return nume; }
    Pozitie getPozitie() const { return pos; }
    void setPozitie(Pozitie p) { pos = p; }
};

#endif