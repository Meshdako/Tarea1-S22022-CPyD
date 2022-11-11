#include <omp.h>
#include <iostream>
#include <iomanip>


using namespace std;
#define MAX_THREADS 8   // Num hilos
static long num_steps = 1000000000; // Num Rectangulos (Precision PI)
double step;


int main() {
    int i;
    double x,pi,sum=0.0;  // iniciando variables
    double start, delta; // Variables para almacenar tiempo de ejecucion

    step = 1.0/(double) num_steps;
    // Define el tamaño de la base de los rectangulos
    omp_set_num_threads(MAX_THREADS); // Define Num Hilos
   start = omp_get_wtime(); // Variable para calculo tiempo Ejecucion

    #pragma omp parallel for reduction(+:sum) private(x) // paralelizacion for
    for ( i = 0; i < num_steps; i++)
    {
        x = (i+0.5)*step;              //Valor de x para f(x), el cual sera la mitad de la base de cada rectangulo
        sum = sum + 4.0/(1.0+x*x);    // Calculo de la altura de cada rectangulo
    }
    pi= step*sum;    // Base * Altura (Total)
    delta = omp_get_wtime() - start;  //Tiempo de termino ejecución
    std::cout << std::setprecision(14); // Num decimales
    cout <<"Valor PI:"<<pi<<", Tiempo Ejecucion:"<<delta<<", Num Threads: "<<MAX_THREADS;
    return 0;
}
