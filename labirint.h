#ifndef LABIRINT_H
#define LABIRINT_H

#include <vector>
#include "celula.h"
#include "pozitie.h"
#include "inamic.h"

class Labirint {
    int linii;
    int coloane;
    std::vector<std::vector<Celula>> harta;

public:
    Labirint(int l, int c);
    void genereazaLabirint();
    void afisareGrafica(const Pozitie& posJucator, const std::vector<Inamic*>& inamici) const;

    int getLinii() const { return linii; }
    int getColoane() const { return coloane; }
    bool estePozitieValida(int x, int y) const;
};

#endif