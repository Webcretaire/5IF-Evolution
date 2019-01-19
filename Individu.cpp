#include "Individu.h"
#include <iostream>

#define REPARTITION_BASE 0.5
#define REPARTITION_MUTATION 1

using namespace std;

double Individu::distanceToOptimal() {
    double distance = 0.0;
    double halfDna = dna.size() / 2.0;

    for (int i = 0; i < halfDna; ++i)
        if ((bool)dna[i] != (bool)dna[dna.size() - i - 1])
            ++distance;

    return distance / halfDna; // Devrait être entre 0 et 1
}

void Individu::affichage() {
    for (auto c : dna)
        cout << (c ? '1' : '0');

    cout << endl;
}

Individu::Individu(int tailleInitiale, mt19937 &generateurAleatoire) {
    nombreMutation = 0;
    bernoulli_distribution bernoulli(REPARTITION_BASE);
    for (int i = 0; i < tailleInitiale; i++)
        dna.push_back(bernoulli(generateurAleatoire));
}

Individu::Individu(Individu &parent) {
    dna = parent.dna;
    nombreMutation = parent.nombreMutation;
}

void Individu::mutation(mt19937 &generateurAleatoire) {
    uniform_int_distribution uniforme(0, (int)dna.size()-1);
    bernoulli_distribution bernoulli_mut(REPARTITION_MUTATION);
    bernoulli_distribution bernoulli_base(REPARTITION_BASE);
    int index = uniforme(generateurAleatoire);
    //application d'une mutation
    if(bernoulli_mut(generateurAleatoire))
        dna[index] = !dna[index];
    else
        dna.insert(dna.begin()+index, (int8_t)bernoulli_base(generateurAleatoire));

    nombreMutation++;
}
