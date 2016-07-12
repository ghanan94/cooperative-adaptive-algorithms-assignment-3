#include <iostream>
#include "aco_tsp.hpp"

int main( int argc, char *argv[] )
{
  srand( time( NULL ) );
  printf( "ACO - TSP\n" );

  ACO_TSP aco_tsp( "problems/p1.txt" );
  //aco_tsp.print_cities();
  aco_tsp.solve( 29, 10000, 0.75 );

  return 0;
}
