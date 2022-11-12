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
    double x,pi,sum=0.0;  // iniciando variables
    double start, delta; // Variables para almacenar tiempo de ejecucion
    
    cout << "Ingrese Numero de Hilos:"<<endl;
    cin >> MAX_THREADS;
    cout << "Ingrese Numero de Rectangulos (Precision):"<<endl;
    cin >> num_steps;

    delta = CalculoPI(MAX_THREADS, num_steps, step, pi);

    cout << setprecision(14); // Num decimales
    cout << "Valor PI: "<< pi <<", Tiempo Ejecucion:" << delta << ", Num Threads: " << MAX_THREADS << endl;
    cout << "Valor PI: 3.1415926535897 (REAL)" << endl;
    return 0;
}
