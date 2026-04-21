#ifndef INAMIC_H
#define INAMIC_H

#include "entitate.h"

class Inamic : public Entitate {
    int puncteAtac;
public:
    Inamic(const std::string& n, Pozitie p, int atac);
    void actioneaza() override;
    void afisare() const override;
};

#endif