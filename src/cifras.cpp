#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <climits>
#include <array>
#include <random>



using namespace std;

template <typename T>

std::ostream& operator <<( std::ostream& os, const std::vector<T>& v){
    os << "{";
    for (int i = 0; i<v.size(); ++i){
        os << v[i];
        if (i != v.size() - 1){
            os << ", ";
        }
    }
    os << "}";
    return os;
}

class Cifras {

    private:

        /// @brief Vector del que se extraen los numeros de forma aleatoria
        vector<int> ConjuntoNumeros = {1,2,3,4,5,6,7,8,9, 10, 25, 50, 75, 100};

        /// @brief Tamaño del vector Extraidos
        const int NUM_EXTRAIDOS = 6;
        
        /// @brief Vector con los numeros extraidos de ConjuntoNumeros de forma aleatoria
        vector<int> Extraidos;

        /// @brief Numero como máximo de tres cifras, que se pretende lograr con S y operaciones aritmeticas {+,-,*,/}
        int Objetivo;

        /// @brief Inicializa el vector de Extraidos de forma aleatoria
        void InicializarExtraidos(){
            random_device rd;
            uniform_int_distribution<> dist(0, ConjuntoNumeros.size()-1);

            for(int i=0; i<NUM_EXTRAIDOS; ++i){
                Extraidos.push_back(ConjuntoNumeros[dist(rd)]);
            }
        }

        /// @brief Inicializa el objetivo de forma aleatoria
        void InicializarObjetivo(){
            random_device rd;
            uniform_int_distribution<> dist(100, 999);
            Objetivo=dist(rd);
        }


    public:

    

        /// @brief Inicializa Extraidos y Objetivo
        Cifras(){
            InicializarExtraidos();
            InicializarObjetivo();
        }


        /// @return ConjuntoNumeros
        vector<int> GetConjuntoNumeros(){
            return ConjuntoNumeros;
        }

        /// @return Extraidos
        vector<int> GetExtraidos(){
            return Extraidos;
        }
        
        pair<int, string> CalcularOperaciones(vector<int> S, int meta, pair<int, string> actual, pair<int, string> best){
            if(actual.first==meta){
                return actual;
            }

            if(meta - actual.first < meta - best.first){
                best = actual;
            }

            vector<int> restantes = S;
            vector<pair<int, string>> operaciones;
            for (int n: S){
                restantes.pop_back();
                operaciones = GeneraOperaciones(actual, n);

                for(auto it : operaciones){
                    CalcularOperaciones(restantes, meta, it, best);
                }


            }
            


        };

        vector<pair<int, string>> GeneraOperaciones(pair<int, string> actual, int n){
            vector<pair<int, string>> provisional;

            provisional.push_back({actual.first+n, actual.second +to_string(actual.first+n)});

            if(actual.first-n >= 0){
                provisional.push_back({actual.first-n,actual.second +to_string(actual.first-n)});
            }

            provisional.push_back({actual.first*n,actual.second +to_string(actual.first*n)});                              

            if(n != 0 && actual.first % n == 0) {
                provisional.push_back({actual.first / n, actual.second + "/" + to_string(n)});
            }


            return provisional;

        };

        /// @brief Inicializa el Juego
        void Play(){
            pair<int, string> actual, best;

            cout << "Comenzamos con la parte de las Cifras." << endl;

            cout << "Conjunto de nunmeros: " << ConjuntoNumeros << endl;

            cout << "Conjunto de " << Extraidos.size() << " numeros extraidos: " << Extraidos << endl;

            cout << "Objetivo: " << Objetivo << endl;

            pair<int, string> resultado = CalcularOperaciones(ConjuntoNumeros, Objetivo, actual, best);

            cout << resultado.first << endl << resultado.second;

        }

        


    

};

int main(int argc, char* argv[]) {

    Cifras juegocifras;
    
    juegocifras.Play();

    return 0;
}


