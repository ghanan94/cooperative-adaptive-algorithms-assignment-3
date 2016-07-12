#include <iostream>
#include "aco_tsp.hpp"

int main( int argc, char *argv[] )
{
  srand( time( NULL ) );
  printf( "ACO - TSP\n" );

  ACO_TSP aco_tsp( "problems/p1.txt" );
  //aco_tsp.print_cities();
  
  unsigned int const num_agents = 29;
  unsigned int const max_iterations = 10000;
  double const pheromone_persistance = 0.5;
  double const alpha = 1.0;
  double const beta = 1.0;

  aco_tsp.solve( num_agents, max_iterations, pheromone_persistance, alpha, beta );

  return 0;
}
