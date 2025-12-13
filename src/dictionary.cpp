#include "../include/dictionary.h"
#include <fstream>
#include <string>
#include <set>
#include <vector>

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

int Dictionary::getOcurrencias(const char c) const{
    int cont = 0;

    for(const string& word : words){
        for(char letter : word){             
            if(letter == c)
                cont++;
        }
    }
}

int Dictionary::getTotalLetras() const{
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

bool Dictionary::esta(const string& word){
    return words.find(word) != words.end();
}

bool Dictionary::erase(const string &word){
    return words.erase(word) > 0;
}

