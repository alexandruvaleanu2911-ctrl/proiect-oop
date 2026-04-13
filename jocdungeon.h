#ifndef JOCDUNGEON_H
#define JOCDUNGEON_H

#include <string>
#include <iostream>
#include "labirint.h"

class JocDungeon {
    std::string numeJucator;
    Labirint* labirint;
public:
    JocDungeon(const std::string& nume, int w, int h);
    ~JocDungeon();
    JocDungeon(const JocDungeon& altul);
    JocDungeon& operator=(const JocDungeon& altul);

    static double calculeazaDificultate();
    void initSesiune();
    friend std::ostream& operator<<(std::ostream& os, const JocDungeon& j);
};

#endif