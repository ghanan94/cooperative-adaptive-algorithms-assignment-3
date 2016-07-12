#include "aco_tsp.hpp" // ACO_TSP
#include "aco_tsp_city.hpp" // ACO_TSP::City
#include <fstream> // std::ifstream, std::getline
#include <sstream> // std::stringstream
#include <cmath> // pow, sqrt
#include "aco_tsp_agent.hpp" // ACO_TSP::Agent
#include <limits> // std::numeric_limits

ACO_TSP::ACO_TSP( std::string const file_name )
{
  this->parse_problem_file( file_name );
}

ACO_TSP::~ACO_TSP()
{
  for( int i = 0; i < cities.size(); ++i )
  {
    delete this->cities[i];
  }
}

void ACO_TSP::print_cities() const
{
  printf( "Cities: \n" );

  for( int i = 0; i < this->cities.size(); ++i )
  {
    printf( "City #%02d @ ( %06.1f, %06.1f )\n", i, this->cities[ i ]->get_x(), this->cities[ i ]->get_y() );
  }
}

void ACO_TSP::solve( unsigned int const population_size, double const pheromone_persistance ) const
{
  std::vector<ACO_TSP::Agent> agents;
  std::vector<std::vector<double>> pheromone_trails;
  double best_cost = std::numeric_limits<double>::max();
  std::vector<unsigned int> best_solution;

  unsigned int const num_cities = this->cities.size();

  // Create agents and assign each to a city.
  for ( int i = 0; i < population_size; ++i )
  {
    ACO_TSP::Agent agent( i % num_cities );

    agents.push_back( agent );
  }

  // Initialize all pheromone trails to have a value of 1.
  for ( int i = 0; i < num_cities; ++i )
  {
    std::vector<double> pheromone_trails_from_city_i;

    for ( int j = i + 1; j < num_cities; ++j )
    {
      pheromone_trails_from_city_i.push_back( 1 );
    }

    pheromone_trails.push_back( pheromone_trails_from_city_i );
  }

  // Do this only for 100 iterations.
  for ( int iteration = 0; iteration < 500; ++iteration )
  {
    double temp_cost = std::numeric_limits<double>::max();
    std::vector<unsigned int> temp_solution;

    this->iterate( agents, pheromone_trails, pheromone_persistance );

    // Find agent with best cost so far and reset agents
    for ( int i = 0; i < population_size; ++i )
    {
      double cost = this->cost( agents[ i ].get_visited_city_history() );

      if ( cost < temp_cost )
      {
        temp_cost = cost;
        temp_solution = agents[ i ].get_visited_city_history();

        if ( cost < best_cost )
        {
          printf( "Previous best_cost = %f, New = %f\n", best_cost, cost );
          best_cost = cost;
          best_solution = agents[ i ].get_visited_city_history();
        }
      }

      agents[ i ].reset_visited_cities( i % num_cities );
    }

    // With best solution this iteration, update pheromone_trails
    // Offline pheremone update
    this->update_pheromone_values( pheromone_trails, temp_solution, pheromone_persistance );
  }

  printf( "Best Cost: %f\n", best_cost );
  printf( "Best Path: " );

  for ( int i = 0; i < best_solution.size(); ++i )
  {
    printf( "%d->", best_solution[ i ] );
  }

  printf("\b\b  \n");
}

void ACO_TSP::parse_problem_file( std::string const file_name )
{
  std::ifstream problem_file;
  std::string line;
  std::string data;

  problem_file.open(file_name);

  if (problem_file.is_open())
  {
    while ( std::getline(problem_file, line) )
    {
      std::stringstream linestream(line);
      int city_num;
      double x;
      double y;

      // City # (Column 1)
      std::getline(linestream, data, ' ');
      city_num = std::stoi(data);

      // X-Coordinate (Column 2)
      std::getline(linestream, data, ' ');
      x = std::stoi(data);

      // Y-Coordinate (Column 3)
      std::getline(linestream, data, ' ');
      y = std::stoi(data);

      ACO_TSP::City *city = new ACO_TSP::City( x, y );
      this->cities.push_back( city );
    }

    problem_file.close();
  } else
  {
    printf("File error\n");
  }
}

/*
 * Euclidean distance is calculated between two points ( x1, y1 ) and ( x2, y2 )
 * as sqrt( ( ( x2 - x1 ) ^ 2 ) + ( ( y2 - y1 ) ^ 2 ) ).
 */
double ACO_TSP::distance( unsigned int const city_a_id, unsigned int const city_b_id ) const
{
  return sqrt( pow( this->cities[ city_b_id ]->get_x() - this->cities[ city_a_id ]->get_x(), 2.0 ) + pow( this->cities[ city_b_id ]->get_y() - this->cities[ city_a_id ]->get_y(), 2.0 ) );
}

double ACO_TSP::get_pheromone_value( std::vector<std::vector<double>> const &pheromone_table, unsigned int const i, unsigned int const j ) const
{
  if (i == j)
  {
    printf("ERROR\n");
  }

  if ( i > j )
  {
    return pheromone_table[ j ][ i - j - 1 ];
  }
  else
  {
    return pheromone_table[ i ][ j - i - 1 ];
  }
}

void ACO_TSP::iterate( std::vector<ACO_TSP::Agent> &agents, std::vector<std::vector<double>> &pheromone_trails, double const pheromone_persistance ) const
{
  unsigned int num_cities = this->cities.size();
  unsigned int population_size = agents.size();

  for( int step = 1; step < num_cities; ++step )
  {
    // Loop through each agent.
    for ( int a = 0; a < population_size; ++a )
    {
      // Check all possible cities to visit from current city.
      std::vector<unsigned int> vistable_cities;
      std::vector<double> values;
      unsigned int selected_city = -1;

      double some_variable = 0;

      for ( int c = 0; c < num_cities; ++c )
      {
        if ( !agents[ a ].check_if_visited( c ) )
        {
          vistable_cities.push_back( c );
          values.push_back( this->get_pheromone_value( pheromone_trails, agents[ a ].get_at_city(), c ) / this->distance( agents[ a ].get_at_city(), c ) );
          some_variable += values.back();
        }
      }

      // Determine which city this agent should progress to.
      double random_value = ( ( double ) rand() / RAND_MAX ) * some_variable;

      for ( int c = 0; c < vistable_cities.size(); ++c )
      {
        random_value -= values[ c ] / some_variable;

        if ( random_value <= 0 )
        {
          // This city is selected.
          selected_city = vistable_cities[ c ];
          break;
        }
      }

      if ( selected_city == -1 )
      {
        printf("-1 %d %d\n", a, step);
        selected_city = vistable_cities.back();
      }

      // Evaporate the trail and add pheremone
      // "Online step_by_step" pheremone update
      double new_pheromone_value = ( this->get_pheromone_value( pheromone_trails, agents[ a ].get_at_city(), selected_city ) * pheromone_persistance ) + ( 1 / this->distance( agents[ a ].get_at_city(), selected_city ) );
      this->set_pheromone_value( pheromone_trails, agents[ a ].get_at_city(), selected_city, new_pheromone_value );

      agents[ a ].set_at_city( selected_city );
    }
  }
}

double ACO_TSP::cost( std::vector<unsigned int> const &solution ) const
{
  double cost = 0;

  for ( int i = 1; i < solution.size(); ++i )
  {
    cost += distance( solution[ i - 1 ], solution[ i ] );
  }

  // We want a closed loop
  cost += distance( solution.front(), solution.back() );

  return cost;
}

void ACO_TSP::update_pheromone_values( std::vector<std::vector<double>> &pheromone_table, std::vector<unsigned int> const &solution, double const pheromone_persistance ) const
{
  double cost = this->cost( solution );

  for ( int i = 1; i < solution.size(); ++i )
  {
    double new_pheromone_value = ( this->get_pheromone_value( pheromone_table, solution[ i - 1 ], solution[ i ] ) * pheromone_persistance ) + ( distance( solution[ i - 1 ], solution[ i ] ) / cost );
    this->set_pheromone_value( pheromone_table, solution[ i - 1 ], solution[ i ], new_pheromone_value );
  }

  double new_pheromone_value = ( this->get_pheromone_value( pheromone_table, solution.front(), solution.back() ) * pheromone_persistance ) + ( distance( solution.front(), solution.back() ) / cost );
  this->set_pheromone_value( pheromone_table, solution.front(), solution.back(), new_pheromone_value );
}

void ACO_TSP::set_pheromone_value( std::vector<std::vector<double>> &pheromone_table, unsigned int const i, unsigned int const j, double const value ) const
{
  if (i == j)
  {
    printf("ERROR\n");
  }

  if ( i > j )
  {
    pheromone_table[ j ][ i - j - 1 ] = value;
  }
  else
  {
    pheromone_table[ i ][ j - i - 1 ] = value;
  }
}
