#include "aco_tsp.hpp" // ACO_TSP
#include "aco_tsp_city.hpp" // ACO_TSP::City
#include <fstream> // std::ifstream, std::getline
#include <sstream> // std::stringstream
#include <cmath> // pow, sqrt
#include "aco_tsp_agent.hpp" // ACO_TSP::Agent

ACO_TSP::ACO_TSP( std::string const file_name )
{
  parse_problem_file( file_name );
}

ACO_TSP::~ACO_TSP()
{
  for( int i = 0; i < cities.size(); ++i )
  {
    delete cities[i];
  }
}

void ACO_TSP::print_cities() const
{
  printf( "Cities: \n" );

  for( int i = 0; i < cities.size(); ++i )
  {
    printf( "City #%02d @ ( %06.1f, %06.1f )\n", i, cities[ i ]->get_x(), cities[ i ]->get_y() );
  }
}

void ACO_TSP::solve( unsigned int const population_size ) const
{
  std::vector<ACO_TSP::Agent> agents;
  std::vector<std::vector<double>> pheromone_trails;

  unsigned int const num_cities = cities.size();

  // Create agents and assign each to a city.
  for ( int i = 0; i < population_size; ++i )
  {
    ACO_TSP::Agent agent( cities[ i % num_cities ] );

    agents.push_back( agent );
  }

  // Initialize all pheromone trails to have a value of 1.
  for ( int i = 0; i < num_cities; ++i )
  {
    std::vector<double> pheromone_trails_from_city_i;

    for ( int j = i + 1; j < num_cities; ++j )
    {
      pheromone_trails_from_city_i.push_back(1);
    }

    pheromone_trails.push_back( pheromone_trails_from_city_i );
  }

  // Do this only for 100 iterations.
  for ( int iteration = 0; iteration < 100; ++iteration )
  {
    // Loop through each agent.
    for ( int a = 0; a < population_size; ++a )
    {
      // Check all possible cities to visit from current city.
      std::vector<ACO_TSP::City *> vistable_cities;

      for ( int c = 0; c < num_cities; ++c )
      {
        if ( !agents[ a ].check_if_visited( cities[ c ] ) )
        {
          vistable_cities.push_back( cities[ c ] );
        }
      }

      // Determine which city this agent should progress to.
    }
  }
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
      cities.push_back( city );
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
double ACO_TSP::distance( ACO_TSP::City const * const city_a, ACO_TSP::City const * const city_b ) const
{
  return sqrt( pow( city_b->get_x() - city_a->get_x(), 2.0 ) + pow( city_b->get_y() - city_a->get_y(), 2.0 ) );
}

double ACO_TSP::get_pheromone_value( std::vector<std::vector<double>> &pheromone_table, unsigned int const i, unsigned int const j )
{

}
