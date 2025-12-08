#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <climits>
#include <array>
#include <random>
#include "cifras.h"


using namespace std;


void Cifras::InicializarExtraidos(){
    random_device rd;
    uniform_int_distribution<> dist(0, ConjuntoNumeros.size()-1);

    for(int i=0; i<NUM_EXTRAIDOS; i++){
            Extraidos[i]=ConjuntoNumeros[dist(rd)];
    }
}

void Cifras::InicializarObjetivo(){
    random_device rd;
    uniform_int_distribution<> dist(100, 999);
    objetivo=dist(rd);
}

