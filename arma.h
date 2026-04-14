#ifndef ARMA_H
#define ARMA_H

#include "obiect.h"

class Arma : public Obiect {
protected:
    int damage;
public:
    Arma(std::string n, int v, int d);
    void afisare() const override;
    // foloseste() ramane pur virtuala, deci Arma e tot abstracta
};

#endif