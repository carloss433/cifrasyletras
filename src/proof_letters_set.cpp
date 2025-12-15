#include <fstream>
#include <iostream>
#include <string>
#include <cassert>

#include "letters_set.h"

using namespace std;
 
void test_size(LettersSet& letras);
void test_score(LettersSet& letras);
void test_insert(LettersSet& letras);
void test_clear_empty_erase();
void test_operador_index(LettersSet& letras);
void test_iterador(LettersSet& letras);
void test_iterador_const(const LettersSet& letras);

int main(int argc, char *argv[])
{

    ifstream letras_base("data/letras.txt");
    LettersSet conjunto_base;
    letras_base >> conjunto_base;
    cout << "Contenido del LettersSet leido del fichero data/letras.txt\n\n" << conjunto_base << endl;
    const LettersSet conjunto_base_constante(conjunto_base);

    test_size(conjunto_base);
    test_score(conjunto_base);
    test_insert(conjunto_base);
    test_clear_empty_erase();
    test_operador_index(conjunto_base);
    test_iterador(conjunto_base);
    test_iterador_const(conjunto_base_constante);
    
  return 0;
}


void test_size(LettersSet& letras) {
    string word = "estructura";
    assert (word.size() == 10);
    cout << "\033[32m Test size superado correctamente \033[0m" << endl;
}

void test_score(LettersSet& letras) {
    string word = "estructura";
    int puntuacion = letras.getScore(word);
    assert (puntuacion == 12);
    cout << "\033[32m Test getScore superado correctamente \033[0m" << endl;
}

void test_insert(LettersSet& letras) {
    LettersSet copia(letras);
    copia.insert(make_pair('?', LetterInfo(1, 10)));
    assert (copia.size() == letras.size() + 1);
    LetterInfo info = copia['?'];
    assert (info.repetitions == 1);
    assert (info.score == 10);
    cout << "\033[32m Test insert superado correctamente \033[0m" << endl;
}

void test_clear_empty_erase() {
    LettersSet letras;
    assert (letras.empty());
    letras.insert(make_pair('a', LetterInfo(5, 1)));
    assert (!letras.empty());
    letras.clear();
    assert (letras.empty());
    letras.insert(make_pair('b', LetterInfo(3, 2)));
    assert (!letras.empty());
    letras.erase('b');
    assert (letras.empty());
    cout << "\033[32m Test clear, empty y erase superado correctamente \033[0m" << endl;
}


void test_operador_index(LettersSet& letras) {
    string word = "ac";
    LetterInfo primera = letras[word[0]];
    LetterInfo segunda = letras[word[1]];
    assert (primera.repetitions == 12);
    assert (primera.score == 1);
    assert (segunda.repetitions == 5);
    assert (segunda.score == 3);
    cout << "\033[32m Test del operador [] superado correctamente \033[0m" << endl;
}

void test_iterador(LettersSet& letras) {
    LettersSet copia;
    copia = letras;
    for (LettersSet::iterator iter = letras.begin(); iter != letras.end(); ++iter) {
        char c = (*iter).first;
        LetterInfo original = letras[c];
        LetterInfo copiado = copia[c];
        assert (original.repetitions == copiado.repetitions);
        assert (original.score == copiado.score);
    }
    cout << "\033[32m Test del iterador superado correctamente \033[0m" << endl;
}

void test_iterador_const(const LettersSet& letras) {
    int contador = 0;
    int longitud = letras.size();
    for (LettersSet::const_iterator iter = letras.begin(); iter != letras.end(); ++iter) {
        contador++;
    }
    assert (contador == longitud);
    contador = 1;
    for (LettersSet::const_iterator iter = --letras.end(); iter != letras.begin(); --iter) {
        contador++;
    }
    assert (contador == longitud);
    cout << "\033[32m Test del iterador const superado correctamente \033[0m" << endl;
}
