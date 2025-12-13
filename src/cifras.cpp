#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <climits>
#include <array>
#include <random>
#include <queue>

using namespace std;


// Sobrecarga del operador << para imprimir vectores directamente

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

// Clase Cifras
// Gestiona la lógica del juego "Cifras y Letras" (parte de cifras).

class Cifras {

    private:

        /// @brief Pool de números disponibles para el sorteo (del 1 al 10 y grandes: 25, 50, 75, 100)
        vector<int> ConjuntoNumeros = {1,2,3,4,5,6,7,8,9, 10, 25, 50, 75, 100};

        /// @brief Cantidad de números que se reparten al jugador
        const int NUM_EXTRAIDOS = 6;

        /// @brief Límite inferior del número objetivo a calcular
        const int MIN_OBJETIVO = 100;

        /// @brief Límite superior del número objetivo a calcular
        const int MAX_OBJETIVO = 999;
        
        /// @brief Vector que almacena los 6 números seleccionados aleatoriamente para jugar
        vector<int> Extraidos;

        /// @brief El número objetivo (entre 100 y 999) que debemos intentar alcanzar
        int Objetivo;

        /// @brief Almacena la mejor solución encontrada hasta el momento {valor_alcanzado, string_operaciones}
        pair <int, string> best;
        
        /// @brief Almacena la diferencia más pequeña encontrada entre un resultado y el Objetivo (0 es solución exacta)
        int DiferenciaMinima;

        /// @brief Selecciona aleatoriamente NUM_EXTRAIDOS números del ConjuntoNumeros
        void InicializarExtraidos(){
            random_device rd; // Semilla para aleatoriedad real
            uniform_int_distribution<> dist(0, ConjuntoNumeros.size()-1);

            for(int i=0; i<NUM_EXTRAIDOS; ++i){
                Extraidos.push_back(ConjuntoNumeros[dist(rd)]);
            }
        }

        /// @brief Genera el número Objetivo aleatorio entre MIN_OBJETIVO y MAX_OBJETIVO
        void InicializarObjetivo(){
            random_device rd;
            uniform_int_distribution<> dist(MIN_OBJETIVO, MAX_OBJETIVO);
            Objetivo=dist(rd);
        }


    public:

        /// @brief Constructor: Prepara el juego generando los números y el objetivo, e inicializa la mejor diferencia
        Cifras(){
            InicializarExtraidos();
            InicializarObjetivo();
            // Inicializamos con una diferencia imposiblemente alta para asegurar que la primera solución sea mejor
            DiferenciaMinima = MAX_OBJETIVO + 1; 
        }
        
        /// @brief Función recursiva principal para buscar la solución
        /// @param S Vector de números disponibles restantes
        /// @param actual El resultado acumulado actual y la cadena de texto con las operaciones realizadas
        void CalcularOperaciones(vector<int> S, pair<int, string> actual ){
            
            // 1. Comprobar qué tan cerca estamos del objetivo con el valor 'actual'
            int diferenciaActual = abs(Objetivo - actual.first);

            // Si encontramos una solución mejor (más cercana) que la anterior, actualizamos 'best'
            if(diferenciaActual < DiferenciaMinima){
                DiferenciaMinima = diferenciaActual;
                best = actual;
            }

            // 2. Casos base de la recursión:
            // - Si no quedan números en el vector S
            // - Si ya hemos encontrado el número exacto (diferencia 0), paramos para no procesar más de lo necesario en esta rama
            if (S.empty() || diferenciaActual == 0) {
                return;
            }
            
            // 3. Paso recursivo: Probar a operar el valor 'actual' con cada número restante en S
            for (size_t i = 0; i < S.size(); ++i) {
                int n = S[i]; // Número candidato para operar

                // Crear el conjunto "restantes" quitando n usado en esta iteración
                vector<int> restantes = S;
                restantes.erase(restantes.begin() + i);

                // Generar todas las operaciones posibles (sumar, restar, mult, div) entre 'actual' y 'n'
                vector<pair<int, string>> operaciones = GeneraOperaciones(actual, n);

                // Llamada recursiva para cada operación generada
                for (const auto& op : operaciones) {
                    CalcularOperaciones(restantes, op);
                }
            }
            
        };

        /// @brief Genera las operaciones aritméticas válidas entre el acumulado y un nuevo número n
        /// @param actual Par actual {valor, string}
        /// @param n Número nuevo con el que operar
        /// @return Vector con los resultados posibles de operar actual con n
        vector<pair<int, string>> GeneraOperaciones(pair<int, string> actual, int n){
            vector<pair<int, string>> ops;
            
            // Suma: Siempre válida
            ops.push_back({actual.first + n, "(" + actual.second + "+" + to_string(n) + ")"});
            
            // Resta: Solo si el resultado es positivo (regla estándar del juego, no se usan negativos)
            if (actual.first - n > 0) 
                ops.push_back({actual.first - n, "(" + actual.second + "-" + to_string(n) + ")"});
            
            // Multiplicación: Evitamos multiplicar por 1 porque no cambia el valor y gasta un número
            // (Nota: se podría añadir n != 1 también)
            ops.push_back({actual.first * n, "(" + actual.second + "*" + to_string(n) + ")"});

            // División: Solo si es exacta (módulo 0) y no dividimos por cero
            if (n != 0 && actual.first % n == 0)
                ops.push_back({actual.first / n, "(" + actual.second + "/" + to_string(n) + ")"});

            return ops;
        };

        /// @brief Inicializa el Juego y muestra los resultados por consola
        void Play(){
            pair<int, string> actual;

            cout << "--- JUEGO DE LAS CIFRAS ---" << endl;
            cout << "Conjunto de numeros total: " << ConjuntoNumeros << endl;
            cout << "Los " << Extraidos.size() << " numeros extraidos: " << Extraidos << endl;
            cout << "Objetivo a conseguir: " << Objetivo << endl;

            pair<int, string> inicio;

            // Bucle inicial: Como necesitamos un valor base para empezar a operar,
            // probamos usando cada uno de los 6 números como punto de partida.
            for (size_t i = 0; i < Extraidos.size(); ++i) {
                int n = Extraidos[i];
            
                // Creamos el vector de restantes quitando el número elegido como inicio
                vector<int> resto = Extraidos;
                resto.erase(resto.begin() + i);

                // El "inicio" es el número tal cual, convertido a string
                inicio = {n, to_string(n)};

                // Lanzamos la búsqueda recursiva
                CalcularOperaciones(resto, inicio);
            }

            cout << "---------------------------" << endl;
            cout << "Mejor valor alcanzado: " << best.first << endl;
            cout << "Operaciones: " << best.second << endl;
            cout << "Diferencia: " << DiferenciaMinima << endl;
        }

};

int main(int argc, char* argv[]) {
    // Instancia e inicio del juego
    Cifras juegocifras;
    juegocifras.Play();

    return 0;
}