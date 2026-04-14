#ifndef SPEAR_H
#define SPEAR_H

#include "arma.h"

class Spear : public Arma {
public:
    // Constructor - default e o arma destul de buna
    Spear(int v = 75, int d = 35);

    void foloseste() override;
    void afisare() const override;
};

#endif