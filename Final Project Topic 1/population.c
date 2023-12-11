// <Here include necessary library(s)>
#include <assert.h>
#include "functions.h"



int generate_random_int(const int lbound, const int ubound)
{
  /* <Here return a random integer between lbound and ubound,
  including both lbound and ubound>*/

  // return value
}

PIXEL *generate_random_image(int width, int height, int max_color)
{
  /* Here we create a random image with type PIXEL
  and the number of pixels are width*height.
  Every pixel has 3 integer value including r,g,b,
  which randomly must be picked from the range 0 to max_color.
  At the end return this image. This image is actually
  an array with width * height number of elements and
  every element has the type PIXEL holding r,g,b.
  */
  // return image
}

Individual *generate_population(int POPULATION_SIZE, int width, int height,
                                int max_color)
{
  /*
  Here we will create the population. every row has a struct of "Individual"
  Every Individual holds a value for "fitness" a stuct of "PPM_IMAGE".
  Every PPM_IMAGE has PIXEL *data which will be generated using generate_random_image.
  width, height, and max_color for all individuals in the population 
  are the same as original image given. At the end you can return the population.
  */
  // This Must be the format of the population and memory allocated for it:
  Individual *population = malloc(POPULATION_SIZE * sizeof(Individual));
  // This means "population" is an array with the size of POPULATION_SIZE
  // Every element has a stuct (or) type Individual and every Individual has ...
  assert(population);

  // <The rest of your code>

  // return population
}
