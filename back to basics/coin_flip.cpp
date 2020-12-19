/* Based on the example code from 
http://www.cplusplus.com/reference/random/binomial_distribution/binomial_distribution/ */

#include <iostream>
#include <chrono>
#include <random>

int main()
{
  // random generator engine from a time-based seed
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator (seed);

  std::binomial_distribution<int> distribution (1,0.5);

  std::cout << "binomial result between [0,1] with p=0.5): ";
  std::cout << distribution(generator);
  std::cout << std::endl;

  return 0;
}