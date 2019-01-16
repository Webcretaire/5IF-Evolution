#include "Individu.h"
#include <random>
#include <iostream>

using namespace std;

double Individu::distanceToOptimal() {
    double distance = 0.0;
    double halfDna = dna.size() / 2.0;

    for (int i = 0; i < halfDna; ++i)
        if (dna.at(i) != dna.at(dna.size() - i - 1))
            ++distance;

    return distance / halfDna; // Devrait être entre 0 et 1
}

void Individu::affichage() {
    for (auto c : dna)
        cout << c;

    cout << endl;
}

Individu::Individu(int tailleInitiale) {
    for (int i = 0; i < tailleInitiale; i++)
        dna.push_back(rand() % 2 ? '1' : '0');
}
