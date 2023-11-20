#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "functions.h"

int main(int argc, char *argv[])
{

    // <Handle the inputs here>
    const char *filename = argv[1];

    CSRMatrix A;
    ReadMMtoCSR(filename, &A);

    // Initializing all the vector b (in Ax=b)
    double *b = (double *)malloc(A.num_rows * sizeof(double));
    // Set all elements of b to 1
    for (int i = 0; i < A.num_rows; ++i)
    {
        b[i] = 1.0;
    }

    // <The rest of your code goes here>
}