#include "aco_tsp.hpp"
#include "aco_tsp_city.hpp" // ACO_TSP::City
#include <fstream> // std::ifstream, std::getline
#include <sstream> // std::stringstream

ACO_TSP::ACO_TSP( std::string file_name )
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

void ACO_TSP::print_cities()
{
  printf( "Cities: \n" );

  for( int i = 0; i < cities.size(); ++i )
  {
    printf( "City #%02d @ ( %06.1f, %06.1f )\n", i, cities[ i ]->get_x(), cities[ i ]->get_y() );
  }
}

void ACO_TSP::parse_problem_file( std::string file_name )
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
