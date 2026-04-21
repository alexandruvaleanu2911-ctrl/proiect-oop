#ifndef INAMIC_H
#define INAMIC_H

#include "entitate.h"
#include <string>

class Inamic : public Entitate {
public:
    Inamic(const std::string& n, Pozitie p, int health);

    void actioneaza() override;
    void afisare() const override;
    void ataca(Entitate& tinta);
};

#endif