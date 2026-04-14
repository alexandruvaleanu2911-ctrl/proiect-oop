#ifndef PISTOALE_H
#define PISTOALE_H

#include "arma.h"

class Pistoale : public Arma {
private:
    int munitie;
public:
    explicit Pistoale(int v = 120, int d = 45, int m = 6);

    void foloseste() override;
    void afisare() const override;
    void reincarca();
};

#endif