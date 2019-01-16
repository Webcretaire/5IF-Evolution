#include <iostream>
#include "World.h"
#include <random>
#include <unistd.h>

using namespace std;

/**
 * Point d'entrée du programme
 *
 * Paramètres disponibles :
 * * -n xxx : xxx individus seront initialement créés
 * * -t xxx : les individus intialement créés auront un ADN de taille xxx
 * * -i xxx : xxx itérations seront exécutées sur le monde généré
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {

    /*
     * Gestion des paramètres
     */

    srand(time(nullptr)); // use current time as seed for random generator

    int opt;

    int tailleInitiale = 0;
    int nombreInitial = 0;
    int iterations = 0;

    while ((opt = getopt(argc, argv, ":n:t:i:")) != -1) {
        switch (opt) {
            case 'n': // Nombre d'individus à créer
                nombreInitial = stoi(optarg);
                break;
            case 't': // Taille des individus (ADN)
                tailleInitiale = stoi(optarg);
                break;
            case 'i': // Nombre d'itérations à exécuter (optionnel)
                iterations = stoi(optarg);
                break;
            default:
                break;
        }
    }

    if (!tailleInitiale || !nombreInitial) {
        cout << "Les paramètres n et t doivent être spécifiés (nombre initial et taille initiale)" << endl
             << "Exemple : ./out -n 10 -t 20 [-i 5]" << endl;
        return 1;
    }

    /*
     * Création du monde
     */

    cout << "=== > Monde initial : " << endl << endl;

    auto *world = new World(nombreInitial, tailleInitiale);

    world->affichage();

    /*
     * Exécution pas à pas
     */

    for (int i = 0; i < iterations; ++i) {
        cout << endl << "=== > Itération " << i << endl << endl;
        world->reproduction();
        world->mort();
        world->affichage(false);
    }

    /*
     * Nettoyage
     */

    cout << endl << "=== > Monde final : " << endl << endl;
    world->affichage();

    delete world;

    return 0;
}