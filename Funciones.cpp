#include "Funciones.h"

double CalculoPI(int MAX_THREADS, long num_steps, double step, double &pi)
{
    // iniciando variables
    double x, sum=0.0;  

    // Variables para almacenar tiempo de ejecucion
    double delta, start;

    step = 1.0/(double) num_steps;
    
    // Define el tamaño de la base de los rectangulos
    omp_set_num_threads(MAX_THREADS); // Define Num Hilos
    start = omp_get_wtime(); // Variable para calculo tiempo Ejecucion

    #pragma omp parallel for reduction(+:sum) private(x) // paralelizacion for
    for (int i = 0; i < num_steps; i++){
        x = (i + 0.5) * step;              //Valor de x para f(x), el cual sera la mitad de la base de cada rectangulo
        sum = sum + 4.0 / (1.0 + (x * x));    // Calculo de la altura de cada rectangulo
    }

    pi = step * sum;    // Base * Altura (Total)
    delta = omp_get_wtime() - start;  //Tiempo de termino ejecución

    return delta;
}