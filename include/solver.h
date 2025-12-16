#ifndef __SOLVER_H__
#define __SOLVER_H__

#include <string>
#include <vector>
#include <map>

#include "letters_set.h"
#include "dictionary.h"

using namespace std;

class Solver {
private:
    Dictionary dictionary;
    LettersSet letters_set;

    // Comprueba si una palabra puede construirse con las letras que tenemos disponibles
    bool canBuildWord(const string &palabra, const vector<char> &letras_disponibles) const;

public:
    // Constructor
    Solver(const Dictionary &dic, const LettersSet &letters);

    // Obtiene las mejores soluciones (por longitud o puntuación)
    pair<vector<string>,int> getSolutions(const vector<char> &letras_disponibles, bool modo_puntuacion);
};

#endif // __SOLVER_H__