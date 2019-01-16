#include <iostream>
#include "Monde.h"

using namespace std;

void Monde::reproduction() {
    // Le meilleur est copié
    auto *nouveau = new Individu(*individus[meilleurIndividu()]);
    nouveau->mutation();
    individus.push_back(nouveau);
}

void Monde::mort() {
    int index = pireIndividu();
    delete individus[index];
    individus.erase(individus.begin() + index);
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
        double distance = individus[0]->distanceToOptimal();

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

int Monde::meilleurIndividu() {
    if (!individus.empty()) {
        double distance = individus[0]->distanceToOptimal();
        int individu = 0;

        for (int i = 0; i < individus.size(); ++i) {
            double temp = individus[i]->distanceToOptimal();
            if (temp < distance) {
                distance = temp;
                individu = i;
            }
        }

        return individu;
    }

    return -1;
}

int Monde::pireIndividu() {
    if (!individus.empty()) {
        double distance = individus[0]->distanceToOptimal();
        int individu = 0;

        for (int i = 0; i < individus.size(); ++i) {
            double temp = individus[i]->distanceToOptimal();
            if (temp > distance) {
                distance = temp;
                individu = i;
            }
        }

        return individu;
    }

    return -1;
}


