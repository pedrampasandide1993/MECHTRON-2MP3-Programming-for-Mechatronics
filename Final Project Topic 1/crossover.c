// File crossover.c
// You don't need to change this unless you have a better algorithm
#include "functions.h"
#include <stdlib.h>

void recombine(Individual *parent1, Individual *parent2, Individual *child1, Individual *child2) {
  // Generate a random number between 0 and image size-1
  int image_size = parent1->image.width * parent1->image.height;
  int crossover = rand() % image_size;
  int i;

  // Technically this the same logic we had in the second assignment
  // Two parents create two children with a random crossover point 
  for (i = 0; i < crossover; i++) {
    child1->image.data[i] = parent1->image.data[i];
    child2->image.data[i] = parent2->image.data[i];
  }
  for (i = crossover; i < image_size; i++) {
    child1->image.data[i] = parent2->image.data[i];
    child2->image.data[i] = parent1->image.data[i];
  }
}

void crossover(Individual *population, int POPULATION_SIZE) {

  for (int i = 0; i < POPULATION_SIZE / 2; i += 2)
    // parent i and i+1 produce children POPULATION_SIZE/2+i and
    // POPULATION_SIZE/2+i+1.
    // This is why I mentioned Pop_size%4=0
    recombine(population + i, population + i + 1,
              population + POPULATION_SIZE / 2 + i,
              population + POPULATION_SIZE / 2 + i + 1);
}
