#ifndef INC_5IF_EVOLUTION_BESLON_INDIVIDU_H
#define INC_5IF_EVOLUTION_BESLON_INDIVIDU_H

#include <vector>

using namespace std;

class Individu {
public:
    explicit Individu(int tailleInitiale);

    double distanceToOptimal();

    void affichage();

    void mutation();

private:
    vector<char> dna;

};


#endif //INC_5IF_EVOLUTION_BESLON_INDIVIDU_H
