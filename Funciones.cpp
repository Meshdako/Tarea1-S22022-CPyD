#include "Funciones.h"

double CalculoPI(int HILOS, long nsteps, double step, double &pi)
{
    // iniciando variables
    double x, suma_area=0.0;  

    // Variables para almacenar tiempo de ejecucion
    double tiempo, inicio;

    step = 1.0/(double) nsteps;
    
    // Define el tamaño de la base de los rectangulos
    omp_set_num_threads(HILOS); // Define Num Hilos
    inicio = omp_get_wtime(); // Variable para calculo tiempo Ejecucion

    #pragma omp parallel for reduction(+:suma_area) private(x) // paralelizacion for
    for (int i = 0; i < nsteps; i++){
        x = (i + 0.5) * step;              //Valor de x para f(x), el cual sera la mitad de la base de cada rectangulo
        suma_area = suma_area + 4.0 / (1.0 + (x * x));    // Calculo de la altura de cada rectangulo
    }

    pi = step * suma_area;    // Base * Altura (Total)
    tiempo = omp_get_wtime() - inicio;  //Tiempo de termino ejecución

    return tiempo;
}