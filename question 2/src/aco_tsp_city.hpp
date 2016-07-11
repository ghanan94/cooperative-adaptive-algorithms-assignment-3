#ifndef __ACO_TSP_CITY__
#define __ACO_TSP_CITY__

#include "aco_tsp.hpp"

class ACO_TSP::City
{
public:
  City( const double, const double );
  const double get_x();
  const double get_y();

private:
  const double x;
  const double y;
};

#endif // __ACO_TSP_CITY__
