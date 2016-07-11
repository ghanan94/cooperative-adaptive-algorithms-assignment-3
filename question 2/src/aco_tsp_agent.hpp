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
   *   ACO_TSP::City const * const city
   *     - Pointer to a city.
   *
   * RETURNS:
   *   N/A
   */
  Agent( ACO_TSP::City const * const );

  /*
   * NAME:          set_at_city
   *
   * DESCRIPTION:   Update the city agent is currently at.
   *
   * PARAMETERS:
   *   ACO_TSP::City const * const city
   *     - Pointer to a city.
   *
   * RETURNS:
   *   N/A
   */
  void set_at_city( ACO_TSP::City const * const );

  /*
   * NAME:          get_at_city
   *
   * DESCRIPTION:   Get the city agent is currently at.
   *
   * PARAMETERS:
   *   N/A
   *
   * RETURNS:
   *   ACO_TSP::City *
   *     - Pointer to a city.
   */
  ACO_TSP::City * get_at_city() const;

  /*
   * NAME:          check_if_visited
   *
   * DESCRIPTION:   Check if a city has been visited by agent.
   *
   * PARAMETERS:
   *   ACO_TSP::City const * const
   *     - Pointer to a city
   *
   * RETURNS:
   *   bool
   *     - returns True if visited; False otherwise.
   */
  bool check_if_visited( ACO_TSP::City const * const ) const;

  /*
   * NAME:          reset_visited_cities
   *
   * DESCRIPTION:   Reset the history of visited cities for this agent. Agent
   *                must be at a city though, so update reset history with a
   *                city.
   *
   * PARAMETERS:
   *   ACO_TSP::City const * const city
   *     - Pointer to a city.
   *
   * RETURNS:
   *   N/A
   */
  void reset_visited_cities( ACO_TSP::City const * const );
  
private:
  /*
   * NAME:          at_city
   *
   * DESCRIPTION:   Pointer to the city agent is currently at.
   *
   */
  ACO_TSP::City *at_city;

  /*
   * NAME:          visited_cities
   *
   * DESCRIPTION:   An unordered_set to keep track of what cities the agent
   *                has already visited.
   *
   */
  std::unordered_set<ACO_TSP::City *> visited_cities;
};

#endif // __ACO_TSP_AGENT__
