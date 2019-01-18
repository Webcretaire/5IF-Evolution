#ifndef INC_5IF_EVOLUTION_BESLON_INDIVIDU_H
#define INC_5IF_EVOLUTION_BESLON_INDIVIDU_H

#include <vector>
#include <random>
#include <cstdint>

using namespace std;

class Individu {
public:
    explicit Individu(int tailleInitiale, mt19937 &generateurAleatoire);

    Individu(Individu& parent);

    double distanceToOptimal();

    void affichage();

    void mutation(mt19937 &generateurAleatoire);

    void vieillir() { age++; }

    int getNombreMutation() { return nombreMutation; }

private:
    vector<int8_t> dna;

    int age = 0;

    int nombreMutation;
};


#endif //INC_5IF_EVOLUTION_BESLON_INDIVIDU_H
