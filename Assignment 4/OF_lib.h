#ifndef OF_H
#define OF_H
// IMPORTANT: DO NOT change this file

// Objective Function prototypes
double griewank(int NUM_VARIABLES, double *x);

double levy(int NUM_VARIABLES, double *x);

double rastrigin(int NUM_VARIABLES, double *x);

double rosenbrock(int NUM_VARIABLES, double *x);

double schwefel(int NUM_VARIABLES, double *x);

double dixon_price(int NUM_VARIABLES, double *x);

double michalewicz(int NUM_VARIABLES, double *x);

double styblinski_tang(int NUM_VARIABLES, double *x);

#endif // OF_H
