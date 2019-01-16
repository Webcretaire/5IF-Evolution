#include <iostream>
#include "World.h"
#include <random>

using namespace std;

int main(int argc, char *argv[]) {
    srand(time(nullptr)); // use current time as seed for random generator

    cout << "Creating world" << endl;

    auto *world = new World(10, 20);

    world->affichage();

    delete world;

    return 0;
}