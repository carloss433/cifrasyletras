#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cassert>

#include "dictionary.h"
#include "letters_bag.h"
#include "letters_set.h"
#include "solver.h"

using namespace std;

void test_solver();

int main(int argc, char *argv[])
{/*
  test_solver();
       */
  return 0;
}
/*
void test_solver(){
    Dictionary dictionary;
    ifstream dict_file("data/diccionario_small.txt");
    dict_file >> dictionary;

    LettersSet letters_set;
    ifstream letters_file("data/letras.txt");
    letters_file >> letters_set;

    Solver solver(dictionary, letters_set);
    vector<char> letras_de_juego = {'b', 'e', 'c', 'o', 'l', 'a', 'r', 'o'};

    pair<vector<string>, int> solutions1 = solver.getSolutions(letras_de_juego, false);
    assert(solutions1.second == 6);
    assert((solutions1.first[0] == "blocao" && solutions1.first[1] == "blocar") ||
           (solutions1.first[1] == "blocao" && solutions1.first[0] == "blocar"));
    cout << "\033[32m Test por longitud superado.\033[0m" << endl;
           
    pair<vector<string>, int> solutions2 = solver.getSolutions(letras_de_juego, true);
    assert(solutions2.second == 10);
    assert((solutions2.first[0] == "blocao" && solutions2.first[1] == "blocar") ||
           (solutions2.first[1] == "blocao" && solutions2.first[0] == "blocar"));
    cout << "\033[32m Test por puntuación superado.\033[0m" << endl;
}
    */