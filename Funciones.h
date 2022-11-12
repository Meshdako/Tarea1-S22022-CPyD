#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <omp.h>
#include <iomanip>

double CalculoPI(int MAX_THREADS, long num_steps, double step, double &pi);

#endif  //FUNCIONES_H