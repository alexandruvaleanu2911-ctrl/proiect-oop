#ifndef INVENTAR_H
#define INVENTAR_H

#include <vector>
#include "obiect.h"

class Inventar {
    std::vector<Obiect*> iteme;
    int capacitateMaxima;

public:
    explicit Inventar(int cap = 5);
    ~Inventar();

    bool adaugaObiect(Obiect* obj);
    void afiseazaTot() const;
    void folosesteToate() ;

    Inventar(const Inventar&) = delete;
    Inventar& operator=(const Inventar&) = delete;
};

#endif