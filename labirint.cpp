#include "labirint.h"

Labirint::Labirint(int w, int h) : latime(w), inaltime(h) {
    initializeazaGrid();
}

void Labirint::initializeazaGrid() {
    for (int i = 0; i < inaltime; ++i) {
        std::vector<Celula> linie;
        for (int j = 0; j < latime; ++j) {
            linie.emplace_back(j, i, true);
        }
        grija.push_back(linie);
    }
}

std::vector<Pozitie> Labirint::gasesteVeciniVizitabili(const Pozitie& p) const {
    std::vector<Pozitie> vecini;
    const int dx[] = {0, 0, 2, -2};
    const int dy[] = {2, -2, 0, 0};

    for (int i = 0; i < 4; i++) {
        int nx = p.getX() + dx[i];
        int ny = p.getY() + dy[i];

        if (nx > 0 && nx < latime - 1 && ny > 0 && ny < inaltime - 1) {
            if (grija[ny][nx].eWorldWall()) {
                vecini.emplace_back(nx, ny);
            }
        }
    }
    return vecini;
}

void Labirint::genereaza(int startX, int startY) {
    std::stack<Pozitie> stack;
    std::mt19937 rng(std::random_device{}());

    grija[startY][startX].spargeZid();
    stack.push(Pozitie(startX, startY));

    while (!stack.empty()) {
        Pozitie curent = stack.top();
        std::vector<Pozitie> vecini = gasesteVeciniVizitabili(curent);

        if (!vecini.empty()) {
            std::shuffle(vecini.begin(), vecini.end(), rng);
            Pozitie urmator = vecini[0];

            int pereteX = (curent.getX() + urmator.getX()) / 2;
            int pereteY = (curent.getY() + urmator.getY()) / 2;

            grija[urmator.getY()][urmator.getX()].spargeZid();
            grija[pereteY][pereteX].spargeZid();

            stack.push(urmator);
        } else {
            stack.pop();
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Labirint& l) {
    for (const auto& linie : l.grija) {
        for (const auto& cel : linie) {
            os << cel;
        }
        os << "\n";
    }
    return os;
}