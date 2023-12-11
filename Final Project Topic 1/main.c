// <Here include necessary library(s)>
#include "functions.h"


int main(int argc, char **argv)
{

  // Process input parameters
  if (argc != 6)
  {
    printf("Usage ./GA <input_file.ppm> <output_file.ppm> <Generation> <Population Size> <Mutation Rate between 0-1>\n");
    return 1;
  }

  // <Here handle th inputs>

  int POPULATION_SIZE = atoi(argv[4]);
  // Here the mutation rate is converted to a % (between 0 to 100)
  double mutation_rate = atof(argv[5]) * 100;

  if (POPULATION_SIZE % 4)
  { 
    // I did this because of the special algorithm I chose for Crossover function
    printf("Population size must be a multiple of 4\n");
    return 1;
  }



  // Read image.
  printf("Reading the image ...\n");
  // <Here call the function to read the input_file.ppm>

  // <Here necessary print outs for the image>

  // Compute image
  // <Here call the evolve_image() to start GA algorithm and receive the best solution>

  // <Here necessary print outs>

  // Write image
  // <Here call the function write_ppm to write the best solution under name output_file.ppm>

  // <Here free memory>
  return (0);
}
