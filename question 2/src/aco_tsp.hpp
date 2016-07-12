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
   *   std::string const file_name
   *     - Path to file that contains the TSP problem.
   *
   * RETURNS:
   *   N/A
   */
  ACO_TSP( std::string const );

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
   *   unsigned int const population_size
   *     - Number of agents.
   *   double const pheromone_persistance
   *     - Pheromone persistance.
   *
   * RETURNS:
   *   N/A
   */
  void solve( unsigned int const, double const ) const;

private:
  /*
   * NAME:          Agent
   *
   * DESCRIPTION:   Forward-declared class. It is actually implemented in
   *                aco_tsp_agent.hpp.
   */
  class Agent;

  /*
   * NAME:          City
   *
   * DESCRIPTION:   Forward-declared class. It is actually implemented in
   *                aco_tsp_city.hpp.
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
  void parse_problem_file( std::string const );

  /*
   * NAME:          distance
   *
   * DESCRIPTION:   Calculates the euclidean distance between two cities.
   *
   * PARAMETERS:
   *   unsigned int const city_a_id
   *     - City id.
   *   unsigned int const city_b_id
   *     - City id.
   *
   * RETURNS:
   *   double
   *     - The euclidean distance between the two cities.
   */
  double distance( unsigned int const, unsigned int const ) const;

  /*
   * NAME:          get_pheromone_value
   *
   * DESCRIPTION:   Get the pheromone value between two cities.
   *
   * PARAMETERS:
   *   std::vector<std::vector<double>> const &pheromone_table
   *     - Reference to a pheromone table
   *   unsigned int const i
   *     - A city id.
   *   unsigned int const j
   *     - A city id.
   *
   * RETURNS:
   *   double
   *     - The pheromone value between two cities.
   */
  double get_pheromone_value( std::vector<std::vector<double>> const &, unsigned int const, unsigned int const ) const;

  /*
   * NAME:          iterate
   *
   * DESCRIPTION:   Complete one iteration of the algorithm. Each ant will
   *                traverse the graph.
   *
   * PARAMETERS:
   *   std::vector<ACO_TSP::Agent> &agents
   *     - Reference to agents.
   *   std::vector<std::vector<double>> &pheromone_table
   *     - Reference to pheromone table.
   *   double const pheromone_persistance
   *     - Pheromone persistance.
   *
   * RETURNS:
   *   N/A
   */
  void iterate( std::vector<ACO_TSP::Agent> &, std::vector<std::vector<double>> &, double const ) const;

  /*
   * NAME:          cost
   *
   * DESCRIPTION:   Calculate cost of a solution.
   *
   * PARAMETERS:
   *   std::vector<unsigned int> const &solution
   *     - Reference to a solution.
   *
   * RETURNS:
   *   double
   *     - Cost of a solution.
   */
  double cost( std::vector<unsigned int> const & ) const;

  /*
   * NAME:          update_pheromone_values
   *
   * DESCRIPTION:   Offline update phermone trail values given a solution path.
   *
   * PARAMETERS:
   *   std::vector<std::vector<double>> &pheromone_table
   *     - Reference to a pheromone table
   *   std::vector<unsigned int> const &
   *     - Refernce to a solution path.
   *   double const pheromone_persistance
   *     - Pheromone persistance.
   *
   * RETURNS:
   *   N/A
   */
  void update_pheromone_values( std::vector<std::vector<double>> &, std::vector<unsigned int> const &, double const ) const;

  /*
   * NAME:          set_pheromone_value
   *
   * DESCRIPTION:   Set the pheromone value between two cities.
   *
   * PARAMETERS:
   *   std::vector<std::vector<double>> &pheromone_table
   *     - Reference to a pheromone table
   *   unsigned int const i
   *     - A city id.
   *   unsigned int const j
   *     - A city id.
   *   double const value
   *     - New value.
   *
   * RETURNS:
   *   N/A
   */
  void set_pheromone_value( std::vector<std::vector<double>> &,  unsigned int const, unsigned int const, double const ) const;
};

#endif // __ACO_TSP__
