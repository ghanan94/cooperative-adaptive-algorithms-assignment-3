#include "aco_tsp_agent.hpp"

ACO_TSP::Agent::Agent( unsigned int const city_id )
{
  this->set_at_city( city_id );
}

void ACO_TSP::Agent::set_at_city( unsigned int const city_id )
{
  // Update city agent is currently at.
  this->at_city = city_id;

  // At new city to the history of visited cities.
  this->visited_cities.insert( city_id );
  this->visited_city_history.push_back( city_id );
}

unsigned int ACO_TSP::Agent::get_at_city() const
{
  return this->at_city;
}

bool ACO_TSP::Agent::check_if_visited( unsigned int const city_id ) const
{
  return this->visited_cities.find( city_id ) != this->visited_cities.end();
}

void ACO_TSP::Agent::reset_visited_cities( unsigned int const city_id )
{
  // Update city agent is currently at.
  this->at_city = city_id;

  // Clear history and add city.
  this->visited_cities.clear();
  this->visited_cities.insert( city_id );
  this->visited_city_history.clear();
  this->visited_city_history.push_back( city_id );
}

std::vector<unsigned int> const & ACO_TSP::Agent::get_visited_city_history() const
{
  return this->visited_city_history;
}
