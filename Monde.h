#ifndef INC_5IF_EVOLUTION_BESLON_WORLD_H
#define INC_5IF_EVOLUTION_BESLON_WORLD_H

#include <vector>
#include "Individu.h"

using namespace std;

class Monde {
public:
    explicit Monde(int nbInitial, int tailleInitiale);

    virtual ~Monde();

    void reproduction();

    void mort();

    void affichage(bool verbose = true);

private:
    vector<Individu *> individus;

    double meilleureDistance();

    double distanceMoyenne();
};


#endif //INC_5IF_EVOLUTION_BESLON_WORLD_H
