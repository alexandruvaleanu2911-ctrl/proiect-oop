#include "celula.h"

Celula::Celula(int x, int y, bool zid) : pos(x, y), esteZid(zid) {}
void Celula::spargeZid() { esteZid = false; }
bool Celula::eWorldWall() const { return esteZid; }

std::ostream& operator<<(std::ostream& os, const Celula& c) {
    os << (c.esteZid ? "█" : " ");
    return os;
}