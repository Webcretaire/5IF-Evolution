#include "Individu.h"
#include <iostream>

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
    uniform_int_distribution<int8_t> generateurBernoulli(0, 1);
    for (int i = 0; i < tailleInitiale; i++)
        dna.push_back(generateurBernoulli(generateurAleatoire));
}

void Individu::mutation(mt19937 &generateurAleatoire) {
    uniform_int_distribution<> uniforme(0, (int)dna.size()-1);
    int index = uniforme(generateurAleatoire);
    dna[index] = !dna[index];
}
