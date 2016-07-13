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

void ACO_TSP::solve( unsigned int const population_size, unsigned int const max_iterations, double const pheromone_persistance, double const alpha, double const beta ) const
{
  // Actual soln from http://elib.zib.de/pub/mp-testdata/tsp/tsplib/tsp/bays29.opt.tour
  std::vector<unsigned int> actual_solution = {0,28,5,11,8,4,25,28,2,1,19,9,3,14,17,16,13,21,10,18,24,6,23,26,7,23,15,12,20};
  printf( "Optimal solution:\n" );
  this->print_solution( actual_solution );

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
      pheromone_trails_from_city_i.push_back( 1.0 );
    }

    pheromone_trails.push_back( pheromone_trails_from_city_i );
  }

  for ( int iteration = 0; iteration < max_iterations; ++iteration )
  {
    double temp_cost = std::numeric_limits<double>::max();
    std::vector<unsigned int> temp_solution;

    this->iterate( agents, pheromone_trails, pheromone_persistance, alpha, beta );

    this->evaporate_pheromone_trails( pheromone_trails, pheromone_persistance );

    // Find agent with best cost so far and reset agents
    for ( int i = 0; i < population_size; ++i )
    {
      double cost = this->cost( agents[ i ].get_visited_city_history() );

      if ( cost < temp_cost )
      {
        temp_cost = cost;
        temp_solution = agents[ i ].get_visited_city_history();
      }

      this->update_pheromone_values( pheromone_trails, agents[ i ].get_visited_city_history() );

      agents[ i ].reset_visited_cities();
    }

    this->evaporate_pheromone_trails( pheromone_trails, pheromone_persistance );
    //this->print_pheromone_table( pheromone_trails );

    if ( temp_cost < best_cost )
    {
      printf( "Previous best_cost = %f, New = %f\n", best_cost, temp_cost );
      best_cost = temp_cost;
      best_solution = temp_solution;
    }
  }

  printf( "Best solution:\n" );
  this->print_solution( best_solution );
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

void ACO_TSP::iterate( std::vector<ACO_TSP::Agent> &agents, std::vector<std::vector<double>> &pheromone_trails, double const pheromone_persistance, double const alpha, double const beta ) const
{
  // Loop through each agent and get next city that agent should go to
  // Set the agent's new location to the selected nect city.
  for ( int a = 0; a < agents.size(); ++a )
  {
    for( int step = 1; step < this->cities.size(); ++step )
    {
      unsigned int selected_city = this->next_city( agents[ a ], pheromone_trails, pheromone_persistance, alpha, beta );

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

  // Closed loop
  cost += distance( solution.back(), solution.front() );

  return cost;
}

void ACO_TSP::update_pheromone_values( std::vector<std::vector<double>> &pheromone_table, std::vector<unsigned int> const &solution ) const
{
  double cost = this->cost( solution );

  for ( int i = 1; i < solution.size(); ++i )
  {
    double new_pheromone_value = this->get_pheromone_value( pheromone_table, solution[ i - 1 ], solution[ i ] ) + ( 1 / cost );
    this->set_pheromone_value( pheromone_table, solution[ i - 1 ], solution[ i ], new_pheromone_value );
  }

  double new_pheromone_value = this->get_pheromone_value( pheromone_table, solution.back(), solution.front() ) + ( 1 / cost );
  this->set_pheromone_value( pheromone_table, solution.back(), solution.front(), new_pheromone_value );
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

void ACO_TSP::print_solution( std::vector<unsigned int> const &solution ) const
{
  printf( "Path: " );

  for ( int i = 0; i < solution.size(); ++i )
  {
    printf( "%d->", solution[ i ] );
  }

  printf( "\b\b  \nCost: %f\n", this->cost( solution ) );
}

void ACO_TSP::evaporate_pheromone_trails( std::vector<std::vector<double>> &pheromone_table, double const pheromone_persistance ) const
{
  // evaporate all trails
  for ( int i = 0; i < pheromone_table.size(); ++i )
  {
    for ( int j = 0; j < pheromone_table[ i ].size(); ++j )
    {
      pheromone_table[ i ][ j ] *= pheromone_persistance;
    }
  }
}

unsigned int ACO_TSP::next_city( ACO_TSP::Agent &agent, std::vector<std::vector<double>> &pheromone_trails, double const pheromone_persistance, double const alpha, double const beta ) const
{
  // Check all possible cities to visit from agent's current city.
  std::vector<unsigned int> vistable_cities;
  std::vector<double> values;
  unsigned int selected_city = -1;

  double some_variable = 0;

  for ( int c = 0; c < this->cities.size(); ++c )
  {
    if ( !agent.check_if_visited( c ) )
    {
      vistable_cities.push_back( c );
      values.push_back( pow( this->get_pheromone_value( pheromone_trails, agent.get_at_city(), c ), alpha ) / pow( this->distance( agent.get_at_city(), c ), beta ) );
      some_variable += values.back();
    }
  }

  // Determine which city this agent should progress to.
  double random_value = ( ( double ) rand() / RAND_MAX ) * some_variable;

  for ( int c = 0; c < vistable_cities.size(); ++c )
  {
    random_value -= values[ c ];

    if ( random_value <= 0 )
    {
      // This city is selected.
      selected_city = vistable_cities[ c ];
      break;
    }
  }

  if ( selected_city == -1 )
  {
    selected_city = vistable_cities.back();
  }

  return selected_city;
}

void ACO_TSP::print_pheromone_table( std::vector<std::vector<double>> const &pheromone_table ) const
{
  printf( "Pheromone Table:\n" );

  for ( int i = 0; i < pheromone_table.size(); ++i )
  {
    for ( int j = 0; j <= i; ++j )
    {
      printf( "(%8.5f) ", 0.0 );
    }

    for ( int j = 0; j < pheromone_table[ i ].size(); ++j )
    {
      printf( "(%8.5f) ", pheromone_table[ i ][ j ] );
    }

    printf( "\n" );
  }
}
