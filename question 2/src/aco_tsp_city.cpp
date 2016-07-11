#include "aco_tsp_city.hpp"

ACO_TSP::City::City( const double x, const double y ) :
x( x ),
y( y ) {}

const double ACO_TSP::City::get_x()
{
  return this->x;
}

const double ACO_TSP::City::get_y()
{
  return this->y;
}
