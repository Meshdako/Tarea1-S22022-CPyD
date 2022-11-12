/**
 * Grupo 01
 * Martín Sobarzo
 * Matías Álvarez
 * Rentao Palominos
 * Cristóbal Abarca
 * Rodrigo Ubilla
 * 
 * Computación Paralela y Distribuida
*/

#include <omp.h>
#include <iostream>
#include <iomanip>

#include "Funciones.h"
#include "Funciones.cpp"

using namespace std;
int MAX_THREADS ;   // Num hilos
static long num_steps; // Num Rectangulos (Precision PI)
double step;

int main() {
    int i;
    double PI;  // iniciando variables
    double TiempoFinal;
    
    cout << "Ingrese Numero de Hilos:"<<endl;
    cin >> MAX_THREADS;
    cout << "Ingrese Numero de Rectangulos (Precision):"<<endl;
    cin >> num_steps;

    TiempoFinal = CalculoPI(MAX_THREADS, num_steps, step, PI);

    cout << setprecision(14); // Num decimales
    cout << "Valor PI: "<< PI <<", Tiempo Ejecucion:" << TiempoFinal << ", Num Threads: " << MAX_THREADS << endl;
    cout << "Valor PI: 3.1415926535897 (REAL)" << endl;
    return 0;
}
