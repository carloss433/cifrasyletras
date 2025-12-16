#include "solver.h"

// Constructor
Solver::Solver(const Dictionary &dic, const LettersSet &letras) {
    dictionary = dic;
    letters_set = letras;
}

// Comprueba si una palabra puede formarse con las letras disponibles
bool Solver::canBuildWord(const string &palabra, const vector<char> &letras_disponibles) const {

    map<char, int> disponibles; // Para guardar cuantas veces aparece la letra disponible
    map<char, int> necesarias; // Cuantas veces necesita cada letra

    // Contamos las letras disponibles
    for (char c : letras_disponibles)
        disponibles[c]++;

    // Contamos las letras necesarias para la palabra
    for (char c : palabra)
        necesarias[c]++;

    // Comprobamos que hay suficientes letras
    for (auto it = necesarias.begin(); it != necesarias.end(); ++it) {
        if (disponibles[it->first] < it->second)
            return false;
    }

    return true;
}

// Devuelve las mejores soluciones
pair<vector<string>,int> Solver::getSolutions(const vector<char> &letras_disponibles, bool modo_puntuacion) {

    pair<vector<string>, int> soluciones;
    int mejor_valor = 0;

    // Recorremos todo el diccionario
    for (Dictionary::iterator it = dictionary.begin();
         it != dictionary.end(); ++it) {

        string palabra = *it;

        // Si no se puede formar con las letras disponibles, se ignora
        if (!canBuildWord(palabra, letras_disponibles))
            continue;

        int valor_actual;

        if (modo_puntuacion) {
            // Modo puntuación
            valor_actual = letters_set.getScore(palabra);
        } else {
            // Modo longitud
            valor_actual = palabra.length();
        }

        // Nueva mejor solución
        if (valor_actual > mejor_valor) {
            soluciones.first.clear();
            soluciones.first.push_back(palabra);
            mejor_valor = valor_actual;
        }
        // Empate
        else if (valor_actual == mejor_valor) {
            soluciones.first.push_back(palabra);
        }
    }
    soluciones.second=mejor_valor;

    return soluciones;
}