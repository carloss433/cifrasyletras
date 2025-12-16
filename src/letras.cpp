#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "dictionary.h"
#include "letters_set.h"
#include "letters_bag.h"
#include "solver.h"

using namespace std;

// Función para mostrar el vector 
void PintaLetras(const vector<char>& letras) {
    for (char c : letras) cout << c << " ";
    cout << endl;
}

int main(int argc, char *argv[]) {
    // Control de argumentos
    if (argc != 5) {
        cerr << "Uso: ./letras <diccionario> <letras> <num_letras> <modalidad(L/P)>" << endl;
        return 1;
    }

    // 1. Carga de Diccionario y LettersSet
    Dictionary diccionario;
    ifstream f_dic(argv[1]);
    if (!f_dic) { cerr << "Error abriendo diccionario" << endl; return 1; }
    f_dic >> diccionario;

    LettersSet conjuntoLetras;
    ifstream f_let(argv[2]);
    if (!f_let) { cerr << "Error abriendo letras" << endl; return 1; }
    f_let >> conjuntoLetras;

    // 2. Preparación del juego
    LettersBag bolsa(conjuntoLetras);
    Solver solucionador(diccionario, conjuntoLetras);
    
    int numLetras = stoi(argv[3]);
    bool modoPuntuacion = (string(argv[4]) == "P");

    char seguir;
    do {
        // 3. Sacar letras y mostrar
        vector<char> letrasDisponibles = bolsa.extractLetters(numLetras);
        cout << "Las letras son: ";
        PintaLetras(letrasDisponibles);

        // 4. Turno Usuario
        string palabraUsuario;
        cout << "Dime tu solucion: ";
        cin >> palabraUsuario;

        int puntosUsuario = 0;
        if (diccionario.exists(palabraUsuario)) { 

             if (modoPuntuacion) puntosUsuario = conjuntoLetras.getScore(palabraUsuario);
             else puntosUsuario = palabraUsuario.length();
        }
        cout << palabraUsuario << " Puntuacion: " << puntosUsuario << endl;

        // 5. Turno Máquina
        cout << "Mis soluciones son:" << endl;
        auto soluciones = solucionador.getSolutions(letrasDisponibles, modoPuntuacion);
        
        for (const string& sol : soluciones.first) {
            cout << sol << " Puntuacion: " << soluciones.second << endl;
        }

        // Mejor solución 
        if (!soluciones.first.empty())
            cout << "Mejor Solucion: " << soluciones.first[0] << endl;
        
        cout << "¿Quieres seguir jugando [S/N]? ";
        cin >> seguir;

    } while (toupper(seguir) == 'S');

    return 0;
}