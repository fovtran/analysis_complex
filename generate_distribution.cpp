#include <iostream>
#include <random>

int main()
{
  /* Seed */
  std::random_device rd;

  /* Random number generator */
  std::default_random_engine generator(rd());

  /* Distribution on which to apply the generator */
  std::uniform_int_distribution<long long unsigned> distribution(0,0xFFFFFFFFFFFFFFFF);

  for (int i = 0; i < 10; i++) {
      std::cout << distribution(generator) << std::endl;
  }

  return 0;
}