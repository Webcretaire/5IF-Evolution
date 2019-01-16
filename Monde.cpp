#include <iostream>
#include "Monde.h"

using namespace std;

void Monde::reproduction() {
    cout << " -- Sélection des individus pour la reproduction/mutation." << endl;
}

void Monde::mort() {
    cout << " -- Sélection des individus pour la mort." << endl;
}

void Monde::affichage(bool verbose) {
    cout << "Meilleure distance à l'optimum : " << meilleureDistance() << endl
         << "Distance moyenne à l'optimum : " << distanceMoyenne() << endl
         << individus.size() << " individus : " << endl;

    if (verbose)
        for (auto individu: individus)
            individu->affichage();
}

double Monde::meilleureDistance() {
    if (!individus.empty()) {
        double distance = individus.at(0)->distanceToOptimal();

        for (auto individu: individus) {
            double temp = individu->distanceToOptimal();
            if (temp < distance) distance = temp;
        }

        return distance;
    }

    return -1;
}

double Monde::distanceMoyenne() {
    if (!individus.empty()) {
        double distance = 0.0;

        for (auto individu: individus) {
            distance += individu->distanceToOptimal() / individus.size();
        }

        return distance;
    }

    return -1;
}

Monde::Monde(int nbInitial, int tailleInitiale) {
    for (int i = 0; i < nbInitial; i++)
        individus.push_back(new Individu(tailleInitiale));
}

Monde::~Monde() {
    for (auto individu : individus)
        delete individu;
}


