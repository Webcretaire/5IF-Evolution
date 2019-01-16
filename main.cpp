#include <iostream>
#include "World.h"
#include <random>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[]) {

    /*
     * Gestion des paramètres
     */

    srand(time(nullptr)); // use current time as seed for random generator

    int opt;

    int tailleInitiale = 0;
    int nombreInitial = 0;

    while ((opt = getopt(argc, argv, ":n:t:")) != -1) {
        switch (opt) {
            case 'n':
                nombreInitial = stoi(optarg);
                break;
            case 't':
                tailleInitiale = stoi(optarg);
                break;
            default:
                break;
        }
    }

    if (!tailleInitiale || !nombreInitial) {
        cout << "Les paramètres n et t doivent être spécifiés (nombre initial et taille initiale)" << endl
             << "Exemple : ./out -n 10 -t 20" << endl;
        return 1;
    }

    /*
     * Création du monde
     */

    cout << "Creating world" << endl;

    /*
     * Exécution pas à pas
     */

    auto *world = new World(nombreInitial, tailleInitiale);

    world->affichage();

    /*
     * Nettoyage
     */

    delete world;

    return 0;
}