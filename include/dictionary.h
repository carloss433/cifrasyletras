//
// Created by 
//

#ifndef DICTIONARY_H
#define DICTIONARY_H


#include <string>
#include <iostream>
#include <set>
#include <fstream>
#include <vector>
using namespace std;

class Dictionary {
private:
    set<string> words;

public:

    /**
    * @brief Constructor por defecto
    * Crea un Dictionary vacío
    */

    Dictionary(){};

    /**
    * @brief Destructor
    */

    ~Dictionary(){}
    
    /**
    * @brief Limpia el Dictionary
    * @post el diccionario queda con 0 palabras
    */

    void clear();

    /**
     * 	@brief Tamaño del diccionario
     *	@return devuelve un entero con el tamaño de diccionario
    */

    int size() const;

    /**
     * 	@brief Busca si existe una palabra en nuestro diccionario 
     * 	@param word: palabra que queremos comprobar 
    *	@return devuelve true si existe, en caso contrario, false
    */

    bool esta(const string& word);

    /**
     * 	@brief Sobrecarga de operador de escritura 
    */

    /**
    * @brief Elimina una palabra del diccionario
    * @param val Palabra a borrar del diccionario
    * @return Booleano que indica si la palabra se ha borrado del diccionario
    */
    
    bool erase(const string &word);

    /**
     * 	@brief Sobrecarga de operador de entrada 
    */

    friend istream & operator>>(istream &is, Dictionary &D );

    /**
     * 	@brief Sobrecarga de operador de lectura 
    */

    friend ostream & operator<<(ostream &os, const Dictionary &D );

    /**
     * 	@brief Indica el numero de apariciones de una letra
     *  @param c: letra a buscar
     *  @return: un entero que indica el numero de apariciones de la letra c
    */

    int getOcurrencias(const char c) const;
    
    /**
    * @brief Indica el numero totales de letras
    * @return Un entero indicando el numero totales de letras
    */

    int getTotalLetras() const;

    /**
     * 	@brief Definicion de iterador de Diccionario
    */

    class iterator{
        private:
            set<string>::iterator it;
    
        public:
            iterator (){}
            
            string operator *(){
                return *it;
            }
      
            iterator & operator ++(){
                ++it;
                return *this;
            }
      
            iterator & operator --(){
                --it;
                return *this;
            }

            bool operator ==(const iterator &i){
                return i.it == it;
            }

            bool operator !=(const iterator &i){
                return i.it != it;
            }
      
            friend class Dictionary;
    };

    iterator begin(){
        iterator i;
        i.it = words.begin();
        return i;
    }

    iterator end(){
	      iterator i;
        i.it = words.end();
	      return i;
    }
};
#endif //DICTIONARY_H