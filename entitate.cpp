#include "entitate.h"

Entitate::Entitate(std::string n, Pozitie p, int health, int atk, int def)
    : nume(n), pos(p), hp(health), hpMax(health), atac(atk), aparare(def) {}

void Entitate::primesteDamage(int dmg) {
    int damageReal = dmg - aparare;
    if (damageReal < 0) damageReal = 0;
    hp -= damageReal;
    if (hp < 0) hp = 0;
}