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

    bool exists(const string& word);

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

    int getOccurrences(const char c) const;
    
    /**
    * @brief Indica el numero totales de letras
    * @return Un entero indicando el numero totales de letras
    */

    int getTotalLetters() const;

    /**
     * 	@brief Definicion de iterador de Diccionario
    */

    class iterator{
        private:
            set<string>::iterator it;

            // Constructor privado que convierte un iterador de set a tu iterador
            iterator(set<string>::iterator i) : it(i) {}
    
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

    class const_iterator{
        private:
            set<string>::const_iterator cit;

            // Constructor privado que convierte un iterador de set a tu iterador
            const_iterator(set<string>::const_iterator i) : cit(i) {}

        public:
            const_iterator (){};
            
            string operator *(){
                return *cit;
            }

            const_iterator & operator++(){
                ++cit;
                return *this;
            }

            const_iterator & operator --(){
                --cit;
                return *this;
            }

            bool operator ==(const const_iterator &i){
                return i.cit == cit;
            }

            bool operator != (const const_iterator &i){
                return i.cit != cit;
            }

            friend class Dictionary;
    };

    /**
     * 	@brief Busca una palabra para ver si existe en el diccionario
     *  @param word: palabra a buscar en el diccionario
     *  @return un iterador que apunta a la palabra si existe, en caso contrario, apunta a end
    */
    iterator find(const string &word);

    /**
    * @brief Obtiene todas las palabras de una longitud
    * param longitud: valor de longitud de la palabras a devolver
    * @return un vector con palabra de la longitud dada
    **/
    vector<string> getWordsLength(int longitud);

    /**
     * 	@brief Insercion de una palabra en el diccionario
     *  @param val: palabra a insertar.
     *  @return pair<iterator, bool> con el iterador a la palabra y true si se ha podido insertar, y en caso contrario false
    */
    pair<iterator, bool> insert(const string &val);


    /**
     * 	@brief Encuentra el rango de palabras que empiezan con un prefijo dado     
     *  @return pair<iterator, iterator> que es el rango de palabras que tienen dicho prefijo.
    */
    pair<iterator, iterator> range_prefix(const string &val);

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






