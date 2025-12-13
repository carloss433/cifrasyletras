#include "../include/dictionary.h"
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include "dictionary.h"

using namespace std;

istream & operator>>(istream &is, Dictionary &D ){
    string word;

    while( is >> word){
        D.words.insert(word);
    }

    return is;
}

ostream& operator<<(ostream &os, const Dictionary &D ){
    set<string>::iterator it;

    for( it=D.words.begin(); it != D.words.end(); ++it ){
        os << (*it) << endl;
    }

    return os;
}

int Dictionary::getOccurrences(const char c) const{
    int cont = 0;

    for(const string& word : words){
        for(char letter : word){             
            if(letter == c)
                cont++;
        }
    }

    return cont;
}

int Dictionary::getTotalLetters() const{
    int total_letras = 0;

    for(const string& word : words){
        total_letras += word.length();
    }
    
    return total_letras;
}

void Dictionary::clear(){
    return words.clear();
}

int Dictionary::size() const{
    return words.size();
}

bool Dictionary::exists(const string& word){
    return words.find(word) != words.end();
}

bool Dictionary::erase(const string &word){
    return words.erase(word) > 0;
}

Dictionary::iterator Dictionary::find(const string &word){
    return iterator(words.find(word));
}

vector<string> Dictionary::getWordsLength(int longitud)
{
    return vector<string>();
}
pair<Dictionary::iterator, bool> Dictionary::insert(const string &val){
    pair<set<string>::iterator, bool> resultado = words.insert(val);
    return make_pair(iterator(resultado.first), resultado.second);
}

pair<Dictionary::iterator, Dictionary::iterator> Dictionary::range_prefix(const string &val){
    set<string>::iterator it_low = words.lower_bound(val); //Primer elemento que no es menor que le prefijo, es decir, donde empieza el rango.

    //Creacion de un limite, que es el prefijo pero cambiando su ultima letra por la que va siguiente en el abecedario.
    string limite = val;
    if(!limite.empty()){
        limite[limite.size() - 1]++;
    }

    //Primer elemento que no es menor que el limite que es donde termina el rango.
    set<string>::iterator it_up = words.lower_bound(limite);

    return make_pair(iterator(it_low), iterator(it_up));
}


