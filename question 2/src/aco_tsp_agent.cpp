#include "aco_tsp_agent.hpp"

ACO_TSP::Agent::Agent( ACO_TSP::City const * const city )
{
  at_city = ( City * ) city;
}

void ACO_TSP::Agent::set_at_city( ACO_TSP::City const * const city )
{
  // Update city agent is currently at.
  this->at_city = ( City * ) city;

  // At new city to the history of visited cities.
  this->visited_cities.insert( ( City * ) city );
}

ACO_TSP::City * ACO_TSP::Agent::get_at_city() const
{
  return this->at_city;
}

bool ACO_TSP::Agent::check_if_visited( ACO_TSP::City const * const city ) const
{
  return this->visited_cities.find( ( City * ) city ) != this->visited_cities.end();
}

void ACO_TSP::Agent::reset_visited_cities( ACO_TSP::City const * const city )
{
  // Update city agent is currently at.
  this->at_city = ( City * ) city;

  // Clear history and add city.
  this->visited_cities.clear();
  this->visited_cities.insert( ( City * ) city );
}
