#ifndef INC_5IF_EVOLUTION_BESLON_WORLD_H
#define INC_5IF_EVOLUTION_BESLON_WORLD_H

#include <vector>
#include <random>
#include "Individu.h"

using namespace std;

class Monde {
public:
    explicit Monde(int nbInitial, int tailleInitiale, double taux, unsigned long graine);

    virtual ~Monde();

    void reproduction();

    void mort();

    void affichage(bool verbose = true);

private:
    vector<Individu *> individus;

    mt19937 generateurAleatoire;

    int nombreReproduction = 0;

    int tempsMeilleur = -1;
    int nombreMutationMeilleur = -1;

    double tauxMutation;

    double meilleureDistance();

    double distanceMoyenne();

    int meilleurIndividu();

    int pireIndividu();

    Individu *selectionReproduction();

    int selectionMort();
};


#endif //INC_5IF_EVOLUTION_BESLON_WORLD_H
