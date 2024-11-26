#include <math.h>
// IMPORTANT: DO NOT change this file
// Objective functions:


double griewank(int NUM_VARIABLES, double *x) {
    // griewank() 
    double sum = 0.0;
    double prod = 1.0;
    double result;
    
    for (int i = 0; i < NUM_VARIABLES; i++) {
        sum += (x[i] * x[i]) / 4000.0;
        prod *= cos(x[i] / sqrt((double)(i + 1)));
    }
    
    result = sum - prod + 1.0;
    return result;
}

double levy(int NUM_VARIABLES, double *x) {
    // levy() 
    // if the number of decison variables are high, we had to allocate memory for `w`. But for this assignment no need
    double w[NUM_VARIABLES]; 
    for (int i = 0; i < NUM_VARIABLES; i++) {
        w[i] = 1.0 + (x[i] - 1.0) / 4.0;
    }

    double term1 = pow(sin(M_PI * w[0]), 2);
    double term2 = 0.0;
    for (int i = 0; i < NUM_VARIABLES - 1; i++) {
        term2 += pow(w[i] - 1.0, 2) * (1 + 10 * pow(sin(M_PI * w[i] + 1.0), 2));
    }
    double term3 = pow(w[NUM_VARIABLES - 1] - 1.0, 2) * (1 + pow(sin(2 * M_PI * w[NUM_VARIABLES - 1]), 2));

    return term1 + term2 + term3;
}


double rastrigin(int NUM_VARIABLES, double *x) {
    // rastrigin() 
    double A = 10.0;
    double sum = A * NUM_VARIABLES;

    for (int i = 0; i < NUM_VARIABLES; i++) {
        sum += pow(x[i], 2) - A * cos(2 * M_PI * x[i]);
    }

    return sum;
}


double rosenbrock(int NUM_VARIABLES, double *x) {
    // rosenbrock() 
    double sum = 0.0;

    for (int i = 0; i < NUM_VARIABLES - 1; i++) {
        double term1 = x[i + 1] - x[i] * x[i];
        double term2 = x[i] - 1.0;
        sum += 100.0 * term1 * term1 + term2 * term2;
    }

    return sum;
}


double schwefel(int NUM_VARIABLES, double *x) {
    // schwefel() with Bonus #####################################
    double sum = 0.0;

    for (int i = 0; i < NUM_VARIABLES; i++) {
        sum += x[i] * sin(sqrt(fabs(x[i])));
    }

    return 418.9829 * NUM_VARIABLES - sum;

}


double dixon_price(int NUM_VARIABLES, double *x) {
    
    // dixon_price() with Bonus ##################################
    double term1 = pow(x[0] - 1.0, 2);
    double term2 = 0.0;

    for (int i = 1; i < NUM_VARIABLES; i++) {
        term2 += (i + 1) * pow(2 * x[i] * x[i] - x[i - 1], 2);
    }

    return term1 + term2;
}


double michalewicz(int NUM_VARIABLES, double *x) {
    
    // michalewicz() with Bonus ##################################
    double m = 10.0;
    double sum = 0.0;

    for (int i = 0; i < NUM_VARIABLES; i++) {
        sum += sin(x[i]) * pow(sin((i + 1) * x[i] * x[i] / M_PI), 2 * m);
    }

    return -sum;
}


double styblinski_tang(int NUM_VARIABLES, double *x) {
   
    // styblinski_tang() with Bonus ##############################
    double sum = 0.0;

    for (int i = 0; i < NUM_VARIABLES; i++) {
        double xi = x[i];
        sum += pow(xi, 4) - 16 * pow(xi, 2) + 5 * xi;
    }
    return 0.5 * sum;
}