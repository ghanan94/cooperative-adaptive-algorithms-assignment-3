#include <iostream>
#include "aco_tsp.hpp"

int main( int argc, char *argv[] )
{
  printf( "ACO - TSP\n" );
  ACO_TSP aco_tsp( "problems/p1.txt" );
  aco_tsp.print_cities();

  return 0;
}
