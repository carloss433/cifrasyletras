#ifndef __LETTERS_BAG_H__
#define __LETTERS_BAG_H__

#include "letters_set.h"
#include <vector>
#include <stdlib.h> 
#include <time.h>  
 
using namespace std;

class LettersBag {
private:
    vector<char> letters;  // Contenedor de letras

public:
    LettersBag();  // Constructor vacío
    LettersBag(const LettersSet &letterSet);  // Constructor con LettersSet

    char extractLetter();  // Extrae una letra
    vector<char> extractLetters(int num);  // Extrae varias letras
    void insertLetter(char c);

    int size() const;  // Devuelve el tamaño de la bolsa
    bool empty() const;  // Indica si la bolsa está vacía
    void clear();  // Limpia la bolsa de letras
};

#endif

