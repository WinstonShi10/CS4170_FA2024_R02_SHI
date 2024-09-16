// Open multi-process library
#include <omp.h>
// Generate Random Numbers
#include <random>
// Adds input/output functionality using streams
#include <iostream>
// Adds a CPU time function
#include "CStopWatch.h"


// Returns the number squared
double f(double x);
// Calculate the area under a wave function using the Trapezoidal Rule
double serialTrap(double a, double b, int n);


int main(){
    // Initialize a pseudorandom number generator
    srandom(time(NULL));
    // Initialize Variable
    double result = 0;
    double a, b;
    int n;
    // Initialize timer
    CStopWatch timer;
    // Reflection #2: Run The function with intervals a=0 and b=16
    a = 0;
    b = 16;
    // Reflection #2: Get a value of 'n' ranging from 10,000 to 100,000 using steps of 10,000
    for(n = 10000; n < 110000; n += 10000) {
        // Reflection #2: Run 1 to 12 threads/processors
        for(int thread_num = 1; thread_num < 13; thread_num++) {
            // Setup OMP threads
            omp_set_num_threads(thread_num);
            // Specify the number of threads
            #pragma omp parallel num_threads(thread_num)
            // Start Timer
            timer.startTimer();
            // Call function for trapezoidal rule
            result = serialTrap(a, b, n);
            // Stop timer
            timer.stopTimer();
            // Output results
            std::cout << "n        Threads     Result     Time" << std::endl;
            std::cout << n << "   ";
            std::cout << thread_num << "           ";
            std::cout << result << "    ";
            std::cout << timer.getElapsedTime() << std::endl;
            // Reset Result
            result = 0.0;
        }
        std::cout << "--------------------------------------" << std::endl;
    }
    return 0;
}


double f(double x) {
    // Multiply the number by itself
    return x * x;
}


double serialTrap(double a, double b, int n) {
    // Initialize floating number variables
    double h, retValue, x;
    // Calculate width interval
    h = (b - a) / n;
    // Approximate initial area under the curve
    retValue = (f(a) + f(b)) / 2.0;
    // Using parallelism, run the Trapezoidal Rule 'n' times
    #pragma omp parallel for reduction(+:retValue)
    for (int i = 1; i < n; i++) {
        x = a + i * h;
        retValue += f(x);
    }
    // multiplying the accumulated area by the interval width
    retValue *= h;
    // return the final area
    return retValue;
}