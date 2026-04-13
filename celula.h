#ifndef CELULA_H
#define CELULA_H

#include "pozitie.h"
#include <iostream>

class Celula {
    Pozitie pos;
    bool esteZid;
public:
    explicit Celula(int x = 0, int y = 0, bool zid = true);
    void spargeZid();
    bool eWorldWall() const;
    friend std::ostream& operator<<(std::ostream& os, const Celula& c);
};

#endif