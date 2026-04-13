#ifndef INAMIC_H
#define INAMIC_H

#include "entitate.h"

class Inamic : public Entitate {
private:
    int putereAtac;

public:
    Inamic(std::string n, Pozitie p, int atac);
    
    void actioneaza() override;
    void afisare() const override;
};

#endif