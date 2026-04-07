#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <random>
#include <string>

class Pozitie {
    int x, y;
public:
    Pozitie(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    int getX() const { return x; }
    int getY() const { return y; }

    friend std::ostream& operator<<(std::ostream& os, const Pozitie& p) {
        os << "(" << p.x << "," << p.y << ")";
        return os;
    }
};

class Celula {
    Pozitie pos;
    bool esteZid;
public:
    Celula(int x = 0, int y = 0, bool zid = true) : pos(x, y), esteZid(zid) {}

    void spargeZid() { esteZid = false; }
    bool eWorldWall() const { return esteZid; }

    friend std::ostream& operator<<(std::ostream& os, const Celula& c) {
        os << (c.esteZid ? "█" : " ");
        return os;
    }
};

class Labirint {
    int latime, inaltime;
    std::vector<std::vector<Celula>> grija;

    void initializeazaGrid() {
        for (int i = 0; i < inaltime; ++i) {
            std::vector<Celula> linie;
            for (int j = 0; j < latime; ++j) {
                linie.emplace_back(j, i, true);
            }
            grija.push_back(linie);
        }
    }

    std::vector<Pozitie> gasesteVeciniVizitabili(const Pozitie& p) const {
        std::vector<Pozitie> vecini;
        int dx[] = {0, 0, 2, -2};
        int dy[] = {2, -2, 0, 0};

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

public:
    Labirint(int w, int h) : latime(w), inaltime(h) {
        initializeazaGrid();
    }

    void genereaza(int startX, int startY) {
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

    friend std::ostream& operator<<(std::ostream& os, const Labirint& l) {
        for (const auto& linie : l.grija) {
            for (const auto& cel : linie) {
                os << cel;
            }
            os << "\n";
        }
        return os;
    }
};

class JocDungeon {
    std::string numeJucator;
    Labirint* labirint;
public:
    JocDungeon(std::string nume, int w, int h) : numeJucator(nume) {
        labirint = new Labirint(w, h);
    }

    ~JocDungeon() {
        delete labirint;
    }

    JocDungeon(const JocDungeon& altul) : numeJucator(altul.numeJucator) {
        labirint = new Labirint(*altul.labirint);
    }

    JocDungeon& operator=(const JocDungeon& altul) {
        if (this != &altul) {
            delete labirint;
            numeJucator = altul.numeJucator;
            labirint = new Labirint(*altul.labirint);
        }
        return *this;
    }

    double calculeazaDificultate() const {
        return 0.5;
    }

    void initSesiune() {
        labirint->genereaza(1, 1);
        std::cout << "Sesiune pornita pentru: " << numeJucator << "\n";
    }

    friend std::ostream& operator<<(std::ostream& os, const JocDungeon& j) {
        os << "Jucator: " << j.numeJucator << "\nDificultate: " << j.calculeazaDificultate() << "\n";
        os << *j.labirint;
        return os;
    }
};

int main() {
    std::string nume;
    int dim;

    if (!(std::cin >> nume >> dim)) return 0;

    JocDungeon joculMeu(nume, dim, dim);
    joculMeu.initSesiune();

    JocDungeon copieJoc = joculMeu;

    std::cout << joculMeu;

    return 0;
}