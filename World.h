#ifndef INC_5IF_EVOLUTION_BESLON_WORLD_H
#define INC_5IF_EVOLUTION_BESLON_WORLD_H

#include <vector>
#include "Individu.h"

using namespace std;

class World {
public:
    explicit World(int nbInitial, int tailleInitiale);

    virtual ~World();

    void reproduction();

    void mort();

    void affichage();

private:
    vector<Individu *> individus;

    double meilleureDistance();

    double distanceMoyenne();
};


#endif //INC_5IF_EVOLUTION_BESLON_WORLD_H
