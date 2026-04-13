#ifndef LABIRINT_H
#define LABIRINT_H

#include <vector>
#include <stack>
#include <random>
#include <algorithm>
#include "celula.h"
#include "pozitie.h"

class Labirint {
    int latime, inaltime;
    std::vector<std::vector<Celula>> grija;

    void initializeazaGrid();
    std::vector<Pozitie> gasesteVeciniVizitabili(const Pozitie& p) const;

public:
    Labirint(int w, int h);
    void genereaza(int startX, int startY);
    friend std::ostream& operator<<(std::ostream& os, const Labirint& l);
};

#endif