#include <fstream>
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cassert>

#include "letters_set.h"
#include "letters_bag.h"

using namespace std;

void test_size(LettersBag &bolsa);
void test_clear(LettersBag &bolsa);
void test_inserta(LettersBag &bolsa);
void test_extraerLetra(LettersBag &bolsa);
void test_extraerLetras(LettersBag &bolsa);
void test_visual_extraccion(LettersBag &bolsa);

int main(int argc, char *argv[])
{/*
  ifstream letras_base("data/letras.txt");
  LettersSet conjunto_base;
  letras_base >> conjunto_base;

  LettersBag bolsa(conjunto_base);

  test_size(bolsa);
  test_clear(bolsa);
  test_inserta(bolsa);
  test_extraerLetra(bolsa);
  test_extraerLetras(bolsa);
  test_visual_extraccion(bolsa);

  return 0;
}

void test_size(LettersBag &bolsa)
{
  assert(bolsa.size() == 95);
  cout << "\033[32m Test size superado\033[0m" << endl;
}

void test_clear(LettersBag &bolsa)
{
  LettersBag copia = bolsa;
  copia.clear();
  assert(copia.size() == 0);
  cout << "\033[32m Test clear superado\033[0m" << endl;
}

void test_inserta(LettersBag &bolsa)
{
  LettersBag copia = bolsa;
  copia.insertLetter('z');
  assert(copia.size() == bolsa.size() + 1);
  cout << "\033[32m Test insertar superado\033[0m" << endl;
}

void test_extraerLetra(LettersBag &bolsa)
{
  LettersBag copia = bolsa;
  char letra = copia.extractLetter();
  assert(copia.size() == bolsa.size() - 1);
  cout << "\033[32m Test extraer letra superado\033[0m" << endl;
}

void test_extraerLetras(LettersBag &bolsa)
{
  LettersBag copia = bolsa;
  int num_letras = 5;
  vector<char> letras = copia.extractLetters(num_letras);
  assert(copia.size() == bolsa.size() - num_letras);
  assert(letras.size() == num_letras);
  cout << "\033[32m Test extraer letras superado\033[0m" << endl;
}

void test_visual_extraccion(LettersBag &bolsa)
{
  cout << "Extrayendo 4 letras de la bolsa:" << endl;  
  vector<char> letras = bolsa.extractLetters(4);
  for (int i = 0; i < letras.size(); ++i){
    cout << letras[i] << endl;
  }
    */
}