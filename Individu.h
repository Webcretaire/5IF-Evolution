#ifndef INC_5IF_EVOLUTION_BESLON_INDIVIDU_H
#define INC_5IF_EVOLUTION_BESLON_INDIVIDU_H

#include <vector>
#include <random>
#include <cstdint>

using namespace std;

class Individu {
public:
    explicit Individu(int tailleInitiale, mt19937 &generateurAleatoire);

    double distanceToOptimal();

    void affichage();

    void mutation(mt19937 &generateurAleatoire);

private:
    vector<int8_t> dna;

};


#endif //INC_5IF_EVOLUTION_BESLON_INDIVIDU_H
