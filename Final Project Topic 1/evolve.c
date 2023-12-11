// <Here include necessary library(s)>
#include "functions.h"

// <Here you can implements the functions you might need like sort function>

PPM_IMAGE *evolve_image(const PPM_IMAGE *orig_image, int num_generations,
                        int POPULATION_SIZE, double mutation_rate)
{

  // <Here yuo need inital allocation you need like Individual *population>

  /* For this initial population you need fitness values so call 
  compute_objective_function() and compare all individuals with
  orig_image->data*/

  // <Here Sort the individuals/images in non-decreasing value of fitness?
  

  for (g = 0; g < num_generations; g++)
  {
    /* Here for every generation do 
    1. crossover
    2. mutations
    3. compute objective function
    4. Sort in non-decreasing fitness you can use qsort() built-in function
    */
    // <Here if necessary you can do print outs for each iteration>
  }

  // <Here do the prints for the final result and save the best solution into new_image


  // <Here release memory>

  // return new_image
}
