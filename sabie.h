#ifndef SABIE_H
#define SABIE_H

#include "arma.h"

class Sabie : public Arma {
public:
    explicit Sabie(int v = 50, int d = 30);
    void foloseste() override;
    void afisare() const override;
};

#endif