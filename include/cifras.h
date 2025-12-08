//
// Created by 
//

#ifndef CIFRAS.H
#define CIFRAS.H


#include <string>
#include <iostream>
#include <set>
#include <vector>

#include <vector>
using namespace std;

class Cifras {

    private:

        /// @brief Vector del que se extraen los numeros de forma aleatoria
        vector<int> ConjuntoNumeros = {1,2,3,4,5,6,7,8,9, 10, 25, 50, 75, 100};

        /// @brief Tamaño del vector Extraidos
        const int NUM_EXTRAIDOS = 6;
        
        /// @brief Vector con los numeros extraidos de ConjuntoNumeros de forma aleatoria
        vector<int> Extraidos;

        /// @brief Numero como máximo de tres cifras, que se pretende lograr con S y operaciones aritmeticas {+,-,*,/}
        int objetivo;

        /// @brief Inicializa el vector de Extraidos de forma aleatoria
        void InicializarExtraidos();

        /// @brief Inicializa el objetivo de forma aleatoria
        void InicializarObjetivo();


    public:





};

#endif CIFRAS.H