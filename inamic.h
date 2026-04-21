#ifndef INAMIC_H
#define INAMIC_H

#include "entitate.h"
#include <string>

class Inamic : public Entitate {
    int puncteAtac;
public:
    Inamic(std::string n, Pozitie p, int health);
    Inamic(const std::string& n, Pozitie p, int atac);
    void actioneaza() override;
    void afisare() const override;
    void ataca(Entitate& tinta);
};

#endif