#ifndef POTIUNE_H
#define POTIUNE_H

#include "obiect.h"

class Potiune : public Obiect {
    int puncteViata;
public:
    Potiune(const std::string& n, int v, int hp);
    void foloseste() override;
    void afisare() const override;
};

#endif