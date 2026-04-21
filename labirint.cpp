#include "labirint.h"
#include "inamic.h"
#include <iostream>

Labirint::Labirint(int l, int c) : linii(l), coloane(c) {
    for (int i = 0; i < linii; ++i) {
        std::vector<Celula> rand;
        for (int j = 0; j < coloane; ++j) {
            bool zidulMeu = (i == 0 || i == linii - 1 || j == 0 || j == coloane - 1);
            rand.push_back(Celula(i, j, zidulMeu));
        }
        harta.push_back(rand);
    }
}

void Labirint::genereazaLabirint() {
    for (int i = 1; i < linii - 1; ++i) {
        for (int j = 1; j < coloane - 1; ++j) {
            harta[i][j].spargeZid();
        }
    }
}

void Labirint::afisareGrafica(const Pozitie& posJucator, const std::vector<Inamic*>& inamici) const {
    std::cout << "\n";
    for (int i = 0; i < linii; ++i) {
        for (int j = 0; j < coloane; ++j) {
            if (i == posJucator.getX() && j == posJucator.getY()) {
                std::cout << " P ";
            } else {
                bool inamicGasit = false;
                for (const auto* inamic : inamici) {
                    if (inamic->getPozitie().getX() == i && inamic->getPozitie().getY() == j) {
                        std::cout << " E ";
                        inamicGasit = true;
                        break;
                    }
                }

                if (!inamicGasit) {
                    if (harta[i][j].eWorldWall()) {
                        std::cout << "###";
                    } else {
                        std::cout << " . ";
                    }
                }
            }
        }
        std::cout << "\n";
    }
}

bool Labirint::estePozitieValida(int x, int y) const {
    if (x >= 0 && x < linii && y >= 0 && y < coloane) {
        return !harta[x][y].eWorldWall();
    }
    return false;
}