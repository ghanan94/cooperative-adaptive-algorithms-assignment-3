#ifndef __ACO_TSP_CITY__
#define __ACO_TSP_CITY__

#include "aco_tsp.hpp"

/*
 * NAME:          City
 *
 * DESCRIPTION:   Private nested class of ACO_TSP. This class will store city
 *                information (x and y coordinates) to solve TSP using ACO.
 */
class ACO_TSP::City
{
public:
  /*
   * NAME:          City
   *
   * DESCRIPTION:   Constructor for City class.
   *
   * PARAMETERS:
   *   const double x
   *     - X coordinate.
   *   const double y
   *     - Y coordinate.
   *
   * RETURNS:
   *   N/A
   */
  City( const double, const double );

  /*
   * NAME:          get_x
   *
   * DESCRIPTION:   Returns the x coordinate.
   *
   * PARAMETERS:
   *   N/A
   *
   * RETURNS:
   *   const double
   *     - The x coordinate.
   */
  const double get_x();

  /*
   * NAME:          get_y
   *
   * DESCRIPTION:   Returns the y coordinate.
   *
   * PARAMETERS:
   *   N/A
   *
   * RETURNS:
   *   const double
   *     - The y coordinate.
   */
  const double get_y();

private:

  /*
   * NAME:          x
   *
   * DESCRIPTION:   X coordinate of where a city is located.
   */
  const double x;

  /*
   * NAME:          y
   *
   * DESCRIPTION:   Y coordinate of where a city is located.
   */
  const double y;
};

#endif // __ACO_TSP_CITY__
