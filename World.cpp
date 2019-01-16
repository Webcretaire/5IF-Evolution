#include <iostream>
#include "World.h"

using namespace std;

void World::reproduction() {
    cout << "Sélection des individus pour la reproduction/mutation." << endl;
}

void World::mort() {
    cout << "Sélection des individus pour la mort." << endl;
}

void World::affichage(bool verbose) {
    cout << "Meilleure distance à l'optimum : " << meilleureDistance() << endl
         << "Distance moyenne à l'optimum : " << distanceMoyenne() << endl
         << individus.size() << " individus : " << endl;

    if (verbose)
        for (auto individu: individus)
            individu->affichage();
}

double World::meilleureDistance() {
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

double World::distanceMoyenne() {
    if (!individus.empty()) {
        double distance = 0.0;

        for (auto individu: individus) {
            distance += individu->distanceToOptimal() / individus.size();
        }

        return distance;
    }

    return -1;
}

World::World(int nbInitial, int tailleInitiale) {
    for (int i = 0; i < nbInitial; i++)
        individus.push_back(new Individu(tailleInitiale));
}

World::~World() {
    for (auto individu : individus)
        delete individu;
}


