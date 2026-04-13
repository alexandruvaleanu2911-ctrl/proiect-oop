#include "jocdungeon.h"

JocDungeon::JocDungeon(const std::string& nume, int w, int h) : numeJucator(nume) {
    labirint = new Labirint(w, h);
}

JocDungeon::~JocDungeon() {
    delete labirint;
}

JocDungeon::JocDungeon(const JocDungeon& altul) : numeJucator(altul.numeJucator) {
    labirint = new Labirint(*altul.labirint);
}

JocDungeon& JocDungeon::operator=(const JocDungeon& altul) {
    if (this != &altul) {
        delete labirint;
        numeJucator = altul.numeJucator;
        labirint = new Labirint(*altul.labirint);
    }
    return *this;
}

double JocDungeon::calculeazaDificultate() {
    return 0.5;
}

void JocDungeon::initSesiune() {
    labirint->genereaza(1, 1);
    std::cout << "Sesiune pornita pentru: " << numeJucator << "\n";
}

std::ostream& operator<<(std::ostream& os, const JocDungeon& j) {
    os << "Jucator: " << j.numeJucator << "\nDificultate: " << JocDungeon::calculeazaDificultate() << "\n";
    os << *j.labirint;
    return os;
}