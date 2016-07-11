#include "aco_tsp_city.hpp" // ACO_TSP::CITY

ACO_TSP::City::City( double const x, double const y ) :
x( x ),
y( y ) {}

double const ACO_TSP::City::get_x() const
{
  return this->x;
}

double const ACO_TSP::City::get_y() const
{
  return this->y;
}
