#ifndef __ACO_TSP_AGENT__
#define __ACO_TSP_AGENT__

#include "aco_tsp.hpp" // ACO_TSP
#include <unordered_set> // std::unordered_set

/*
 * NAME:          Agent
 *
 * DESCRIPTION:   Private nested class of ACO_TSP. This class will have
 *                information for each agent (ant in ACO).
 */
class ACO_TSP::Agent
{
public:
  /*
   * NAME:          Agent
   *
   * DESCRIPTION:   Constructor for Agent class.
   *
   * PARAMETERS:
   *   unsigned int const city_id
   *     - City id.
   *
   * RETURNS:
   *   N/A
   */
  Agent( unsigned int const );

  /*
   * NAME:          set_at_city
   *
   * DESCRIPTION:   Update the city agent is currently at.
   *
   * PARAMETERS:
   *   unsigned int const city_id
   *     - City id.
   *
   * RETURNS:
   *   N/A
   */
  void set_at_city( unsigned int const );

  /*
   * NAME:          get_at_city
   *
   * DESCRIPTION:   Get the city agent is currently at.
   *
   * PARAMETERS:
   *   N/A
   *
   * RETURNS:
   *   unsigned int
   *     - City id.
   */
  unsigned int get_at_city() const;

  /*
   * NAME:          check_if_visited
   *
   * DESCRIPTION:   Check if a city has been visited by agent.
   *
   * PARAMETERS:
   *   unsigned int const city_id
   *     - City id.
   *
   * RETURNS:
   *   bool
   *     - returns True if visited; False otherwise.
   */
  bool check_if_visited( unsigned int const ) const;

  /*
   * NAME:          reset_visited_cities
   *
   * DESCRIPTION:   Reset the history of visited cities for this agent. Agent
   *                must be at a city though, so update reset history with a
   *                city.
   *
   * PARAMETERS:
   *   unsigned int const city_id
   *     - City id.
   *
   * RETURNS:
   *   N/A
   */
  void reset_visited_cities( unsigned int const );

  /*
   * NAME:          get_visited_city_history
   *
   * DESCRIPTION:   Get the history of cities agent traveled in an interation.
   *
   * PARAMETERS:
   *   N/A
   *
   * RETURNS:
   *   std::vector<unsigned int> &
   *     - Reference to a history.
   */
  std::vector<unsigned int> const & get_visited_city_history() const;

private:
  /*
   * NAME:          at_city
   *
   * DESCRIPTION:   City id agent is currently at.
   *
   */
  unsigned int at_city;

  /*
   * NAME:          visited_cities
   *
   * DESCRIPTION:   An unordered_set to keep track of what cities the agent
   *                has already visited. Used only to check if visited.
   *
   */
  std::unordered_set<unsigned int> visited_cities;

  /*
   * NAME:          visited_city_history
   *
   * DESCRIPTION:   A vector to keep track of what cities were visited in order.
   *                The difference between this and <visited_cities> is that
   *                <visited_cities> is used to check if visited, and this is
   *                used to show exact travel history.
   *
   */
  std::vector<unsigned int> visited_city_history;
};

#endif // __ACO_TSP_AGENT__
