#ifndef INCLUDED_functions_H
#define INCLUDED_functions_H

// ##########################################################################
// DO NOT CHANGE anything in this part
typedef struct { unsigned char r, g, b; } PIXEL;

typedef struct {
  PIXEL *data;       // pointer to an array of width*height PIXELs
  int width, height; // width and height of image
  int max_color;     // largest value of a color
} PPM_IMAGE;

typedef struct {
  PPM_IMAGE image; // image
  double fitness;  // fitness
} Individual;

// Read and write PPM file
PPM_IMAGE *read_ppm(const char *file_name);
void write_ppm(const char *file_name, const PPM_IMAGE *image);

// Random image and population
PIXEL *generate_random_image(int width, int height, int max_color);
Individual *generate_population(int POPULATION_SIZE, int width, int height, int max_color);

// Fitness
double Objective_function(const PIXEL *A, const PIXEL *B, int image_size);
void compute_objective_function(const PIXEL *image, Individual *individual, int POPULATION_SIZE);

// Free image
void free_image(PPM_IMAGE *p);

int generate_random_int(const int lbound, const int ubound);

// ##########################################################################


// ##########################################################################
// You can make changes this part if you have really a good explanation

// Compute image
PPM_IMAGE *evolve_image(const PPM_IMAGE *image, int num_generations, int POPULATION_SIZE, double rate);

// Crossover
void crossover(Individual *individual, int POPULATION_SIZE);

// Mutation
void mutate(Individual *individual, int POPULATION_SIZE, double rate);
// ##########################################################################



#endif
