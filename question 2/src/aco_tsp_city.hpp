#ifndef __ACO_TSP_CITY__
#define __ACO_TSP_CITY__

#include "aco_tsp.hpp" // ACO_TSP

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
  City( double const, double const );

  /*
   * NAME:          get_x
   *
   * DESCRIPTION:   Returns the x coordinate.
   *
   * PARAMETERS:
   *   N/A
   *
   * RETURNS:
   *   double const
   *     - The x coordinate.
   */
  double const get_x() const;

  /*
   * NAME:          get_y
   *
   * DESCRIPTION:   Returns the y coordinate.
   *
   * PARAMETERS:
   *   N/A
   *
   * RETURNS:
   *   double const
   *     - The y coordinate.
   */
  double const get_y() const;

private:
  /*
   * NAME:          x
   *
   * DESCRIPTION:   X coordinate of where a city is located.
   */
  double const x;

  /*
   * NAME:          y
   *
   * DESCRIPTION:   Y coordinate of where a city is located.
   */
  double const y;
};

#endif // __ACO_TSP_CITY__
