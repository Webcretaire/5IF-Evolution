#include <iostream>
#include "Monde.h"

//#define SELECTION_MEILLEUR

using namespace std;

void Monde::reproduction() {
    nombreReproduction++;
    bernoulli_distribution bernoulli(tauxMutation);
    //On selection un individu pour se reproduire
    auto elu = selectionReproduction();
    elu->vieillir();
    auto *nouveau = new Individu(*elu);

    if (bernoulli(generateurAleatoire))
        nouveau->mutation(generateurAleatoire);

    individus.push_back(nouveau);
}

void Monde::mort() {
    int index = selectionMort();
    delete individus[index];
    individus.erase(individus.begin() + index);
}

void Monde::affichage(bool verbose) {
    int indiceMeilleur = meilleurIndividu();
    double meilleur = individus[indiceMeilleur]->distanceToOptimal();
    cout << "Meilleure distance à l'optimum : " << meilleur << endl
         << "Distance moyenne à l'optimum : " << distanceMoyenne() << endl
         << individus.size() << " individus : " << endl;

    if (meilleur == 0.0 && tempsMeilleur < 0 && nombreMutationMeilleur < 0) {
        tempsMeilleur = nombreReproduction;
        nombreMutationMeilleur = individus[indiceMeilleur]->getNombreMutation();
        cout << "Un individu optimal vient d'apparaitre après " << tempsMeilleur << " reproduction(s)" << endl
             << "L'individu optimal a muté " << nombreMutationMeilleur << " fois" << endl;
        individus[indiceMeilleur]->affichage();
    }

    if (verbose) {
        for (auto individu: individus)
            individu->affichage();
        if (nombreReproduction > 0) {
            if (tempsMeilleur >= 0) {
                cout << "Un individu optimal est apparu après " << tempsMeilleur << " reproduction(s)" << endl;
                cout << "Il est apparu suit à " << nombreMutationMeilleur << " mutation(s)" << endl;
            } else
                cout << "Aucun individu optimal n'est apparu" << endl;
        }
    }
}

double Monde::meilleureDistance() {
    return individus[meilleurIndividu()]->distanceToOptimal();
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

Monde::Monde(int nbInitial, int tailleInitiale, double taux, unsigned long graine)
        : tauxMutation(taux) {
    generateurAleatoire.seed(graine);
    for (int i = 0; i < nbInitial; i++)
        individus.push_back(new Individu(tailleInitiale, generateurAleatoire));
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

Individu *Monde::selectionReproduction() {
#ifdef SELECTION_MEILLEUR
    return individus[meilleurIndividu()];
#else
    uniform_int_distribution uniforme(0, (int)individus.size()-1);
    int indice_elu = uniforme(generateurAleatoire);
    cout << "l'individu sélectionné est a " << individus[indice_elu]->distanceToOptimal() << " de l'optimal" << endl;
    return individus[indice_elu];
#endif //SELECTION_MEILLEUR
}

int Monde::selectionMort() {
    return pireIndividu();
}


