#include <iostream>
#include "Monde.h"
#include <unistd.h>

#define USAGE "./out -n ENTIER -t ENTIER [-i ENTIER] [-m REEL]"

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

//Declaration des paramètres de simulation
    int tailleInitiale = 0;
    int nombreInitial = 0;
    int iterations = 0;
    double tauxMutation = 0.5;
    auto graine = static_cast<unsigned long>(time(nullptr));

    int opt;
    while ((opt = getopt(argc, argv, "n:t:i:m:")) != -1) {
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
            case 'm': // taux de mutation (optionnel)
                tauxMutation = stod(optarg);
                if(tauxMutation < 0 || tauxMutation > 1) {
                    cerr << "Le taux de mutation doit être entre 0 et 1" << endl;
                    exit(EXIT_FAILURE);
                }
                break;
            default:
                cerr << USAGE << endl;
                exit(EXIT_FAILURE);
        }
    }

    if (!tailleInitiale || !nombreInitial) {
        cout << "Les paramètres n et t doivent être spécifiés (nombre initial et taille initiale)" << endl
             << "usage : " USAGE << endl;
        return 1;
    }

    /*
     * Création du monde
     */

    cout << "=== > Monde initial : " << endl << endl;

    auto *world = new Monde(nombreInitial, tailleInitiale, tauxMutation, graine);

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