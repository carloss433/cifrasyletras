#ifndef __LETTER_SET_H__
#define __LETTER_SET_H__

#include <iostream>
#include <map>
#include <string>

using namespace std;



struct LetterInfo{
  unsigned int repetitions;
  unsigned int score;

  /**
   * @brief Constructor por defecto
   */
  LetterInfo(): repetitions(0), score(0){}

  /**
   * @brief Constructor con parámetros
   *
   * @param reps Número de repeticiones del carácter en la partida
   * @param score Puntuación del carácter
   */
  LetterInfo(unsigned int reps, unsigned int score): repetitions(reps), score(score){};
};


class LettersSet{
private:
  map<char, LetterInfo> charSet;
   // A completar

public:

  LettersSet(){};

  LettersSet(const LettersSet& copia): charSet(copia.charSet){};

  int getScore(string word);

  int size() const;

  void insert(const pair<char, LetterInfo>& set);

  bool empty();

  void clear();

  void erase(char c);

  LetterInfo operator[](const char &val);

  friend istream &operator>>(istream &is, LettersSet &let);
  friend ostream &operator<<(ostream &os, const LettersSet &let);

  class iterator {
    private:
        map<char, LetterInfo>::iterator it;

    public:
        iterator() {}

        iterator(const map<char, LetterInfo>::iterator &i) : it(i) {}

        pair<const char, LetterInfo>& operator*() {
            return *it;
        }

        // Operador ++ (Pre-incremento: ++it)
        iterator& operator++() {
            ++it;
            return *this;
        }

        // Operador -- (Pre-decremento: --it)
        iterator& operator--() {
            --it;
            return *this;
        }

        // Operadores de comparación
        bool operator==(const iterator &other) const {
            return it == other.it;
        }

        bool operator!=(const iterator &other) const {
            return it != other.it;
        }

        friend class LettersSet;
    };


    class const_iterator {
    private:
        map<char, LetterInfo>::const_iterator it;

    public:
        const_iterator() {}
        const_iterator(const map<char, LetterInfo>::const_iterator &i) : it(i) {}

        const pair<const char, LetterInfo>& operator*() const {
            return *it;
        }

        const_iterator& operator++() {
            ++it;
            return *this;
        }

        const_iterator& operator--() {
            --it;
            return *this;
        }

        bool operator==(const const_iterator &other) const {
            return it == other.it;
        }

        bool operator!=(const const_iterator &other) const {
            return it != other.it;
        }

        friend class LettersSet;
    };

    iterator begin() {
        return iterator(charSet.begin());
    }

    iterator end() {
        return iterator(charSet.end());
    }

    // Versión constante (para cuando pasas LettersSet con const&)
    const_iterator begin() const {
        return const_iterator(charSet.begin());
    }

    const_iterator end() const {
        return const_iterator(charSet.end());
    }
  
};

#endif
