#ifndef JOCDUNGEON_H
#define JOCDUNGEON_H

#include <string>
#include <vector>
#include <iostream>
#include "labirint.h"
#include "jucator.h"
#include "inamic.h"

class JocDungeon {
    std::string numeSesiune;
    Labirint labirint;

public:
    JocDungeon(std::string nume, int l, int c);
    void initSesiune();
    void verificaInteractiune(Jucator& p, std::vector<Inamic*>& inamici);

    Labirint& getLabirint() { return labirint; }
    const Labirint& getLabirint() const { return labirint; }

    friend std::ostream& operator<<(std::ostream& os, const JocDungeon& joc);
};

#endif