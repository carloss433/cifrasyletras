#include "letters_bag.h"
#include <cstdlib>  // Necesario para rand()
#include <ctime>    // Necesario para srand()

// Constructor vacío
LettersBag::LettersBag() {
    srand(time(NULL));  // Inicializa la semilla del generador de números aleatorios
}

// Constructor con LettersSet
LettersBag::LettersBag(const LettersSet &letterSet) {
    srand(time(NULL));  // Inicializa la semilla del generador de números aleatorios

    // Recorre el conjunto de letras y cantidades
    for (auto it = letterSet.begin(); it != letterSet.end(); ++it) {
        char letter = (*it).first;  // Letra
        int cantidad = (*it).second.repetitions;  // Cantidad de veces que aparece dicha letra

        // Añade la letra a la bolsa tantas veces como su cantidad
        for (int i = 0; i < cantidad; i++) {
            letters.push_back(letter);
        }
    }
}

// Extrae una letra de la bolsa
char LettersBag::extractLetter() {
    if (letters.empty()) {
        return '\0';  // Si la bolsa está vacía, devolvemos un valor nulo
    }

    // Calculamos una posición aleatoria para extraer una letra
    int pos = rand() % letters.size();
    char letter = letters[pos];

    // Borramos la letra extraída
    letters.erase(letters.begin() + pos);
    return letter;
}

// Extrae varias letras de la bolsa (una en cada iteración)
vector<char> LettersBag::extractLetters(int num) {
    vector<char> resultado;

    // Extrae letras hasta alcanzar 'num' o hasta que la bolsa esté vacía
    for (int i = 0; i < num && !letters.empty(); i++) {
        resultado.push_back(extractLetter());  // Extraemos una letra por iteración
    }

    return resultado;
}

void LettersBag::insertLetter(char c)
{
    letters.push_back(c);

}

// Devuelve el tamaño actual de la bolsa de letras
int LettersBag::size() const {
    return letters.size();
}

// Comprueba si la bolsa de letras está vacía
bool LettersBag::empty() const {
    return letters.empty();
}

// Limpia la bolsa de letras
void LettersBag::clear() {
    letters.clear();
}



