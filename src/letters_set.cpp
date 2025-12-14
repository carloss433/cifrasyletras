#include "letters_set.h"



  int LettersSet::getScore(string word){
    int puntuacion = 0;
    for(char c : word){
      puntuacion += charSet.find(c)->second.score;
    }
    return puntuacion;
  }

  istream &operator>>(istream &is, LettersSet &let)
  {
      char letra;
      int cantidad, puntos;
      string cabecera;

      getline(is, cabecera);
      while(is >> letra >> cantidad >> puntos){
        LetterInfo info(cantidad, puntos);
        let.charSet[letra] = info;
      }
      
      return is;
  }

  ostream &operator<<(ostream &os, const LettersSet &let)
  {
      os << "Letra Cantidad Puntos"<< endl;

      for (auto it = let.charSet.begin(); it != let.charSet.end(); ++it){
        os << it->first << "\t"
           << it->second.repetitions << "\t"
           << it->second.score << endl;
      }

      return os;
  }
