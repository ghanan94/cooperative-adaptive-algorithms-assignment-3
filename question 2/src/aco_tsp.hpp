#ifndef __ACO_TSP__
#define __ACO_TSP__

#include <vector>
#include <string>

class ACO_TSP
{
public:
  ACO_TSP( std::string );
  ~ACO_TSP();
  void print_cities();

private:
  class City;
  std::vector<City *> cities;
  void parse_problem_file( std::string );
};


#endif // __ACO_TSP__
