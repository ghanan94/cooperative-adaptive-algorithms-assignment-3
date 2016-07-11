#include "aco_tsp_city.hpp"

ACO_TSP::City::City( const double x, const double y ) :
x( x ),
y( y ) {}

const double ACO_TSP::City::get_x() const
{
  return this->x;
}

const double ACO_TSP::City::get_y() const
{
  return this->y;
}
