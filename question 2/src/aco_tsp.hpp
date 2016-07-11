#ifndef __ACO_TSP__
#define __ACO_TSP__

#include <vector> // std::vector
#include <string> // std::string

/*
 * NAME:          ACO_TSP
 *
 * DESCRIPTION:   Class that will parse a TSP and solve it using ACO.
 */
class ACO_TSP
{
public:
  /*
   * NAME:          ACO_TSP
   *
   * DESCRIPTION:   Constructor for ACO_TSP class.
   *
   * PARAMETERS:
   *   const std::string file_name
   *     - Path to file that contains the TSP problem.
   *
   * RETURNS:
   *   N/A
   */
  ACO_TSP( const std::string );

  /*
   * NAME:          ~ACO_TSP
   *
   * DESCRIPTION:   Deconstructor for ACO_TSP class. Delete all instances of
   *                city storted in cities vector.
   *
   * PARAMETERS:
   *   N/A
   *
   * RETURNS:
   *   N/A
   */
  ~ACO_TSP();

  /*
   * NAME:          print_cities
   *
   * DESCRIPTION:   Print each city and it's coordinates.
   *
   * PARAMETERS:
   *   N/A
   *
   * RETURNS:
   *   N/A
   */
  void print_cities() const;

  /*
   * NAME:          solve
   *
   * DESCRIPTION:   Solve the TSP using ACO.
   *
   * PARAMETERS:
   *   const unsigned int population_size
   *     - Number of agents.
   *
   * RETURNS:
   *   N/A
   */
  void solve( const unsigned int ) const;

private:
  /*
   * NAME:          City
   *
   * DESCRIPTION:   Forward-declared class. It is actually implemented in
   *                aso_tsp_city.hpp.
   */
  class City;

  /*
   * NAME:          cities
   *
   * DESCRIPTION:   A vector of pointers to City (see above).
   */
  std::vector<City *> cities;

  /*
   * NAME:          parse_problem_file
   *
   * DESCRIPTION:   Parse a given file and populate the cities vector.
   *
   * PARAMETERS:
   *   const std::string file_name
   *     - Path to file that contains the TSP problem formatted in rows
   *       representing cities. Each row has 3 columns. Column1 = city number,
   *       Column2 = X-coordinate, and Column3 = Y-coordinate.
   *
   * RETURNS:
   *   N/A
   */
  void parse_problem_file( const std::string );

  /*
   * NAME:          distance
   *
   * DESCRIPTION:   Calculates the euclidean distance between two cities.
   *
   * PARAMETERS:
   *   const City const *city_a
   *     - Pointer to a city.
   *   const City const *city_a
   *     - Pointer to a city.
   *
   * RETURNS:
   *   double
   *     - The euclidean distance between the two cities.
   */
  const double distance( City const * const, City const * const ) const;
};

#endif // __ACO_TSP__
