/**
 * File is a shortened version of http://www.boost.org/libs/random/random_demo.cpp
 *
 * I used it to prove out boost::random generator.  This example
 * generates a random normally distributed generator with mean = 0
 * variance = 1.
 * It uses a rand48 generator.
 *
 * Boost notes below:
 * boost random_demo.cpp profane demo
 *
 * Copyright Jens Maurer 2000
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * $Id: random_demo.cpp,v 1.17 2005/05/10 20:40:59 jmaurer Exp $
 *
 * A short demo program how to use the random number library.
 *
 * @file boostRandomExample.cpp
 */

#include <iostream>
#include <fstream>
#include <ctime>

#include <boost/random/linear_congruential.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/uniform_real.hpp>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/variate_generator.hpp>
#include <boost/generator_iterator.hpp>



// This is a reproducible simulation experiment.  See main().
double generateRandom(base_generator_type& generator)
{
  // Define a uniform random number distribution of integer values between
  // 1 and 6 inclusive.
  typedef boost::rand48 base_generator_type;
  typedef boost::normal_distribution<double> distribution_type;
  typedef boost::variate_generator<base_generator_type&, distribution_type> gen_type;
  gen_type rand(generator, distribution_type(0,1));
  return rand();
}


// This is a typedef for a random number generator.
// Try boost::mt19937 or boost::ecuyer1988 instead of boost::minstd_rand
typedef boost::rand48 base_generator_type;

int main()
{

  const unsigned int NUM_SAMPLES = 10;
  // Define a random number generator and initialize it with a reproducible
  // seed.
  // (The seed is unsigned, otherwise the wrong overload may be selected
  // when using mt19937 as the base_generator_type.)
  const int SEED = 42;
  base_generator_type generator(SEED);

  std::cout << "10 samples of a normal distribution with mean = 0, variance = 1 :\n";

  // Define a normal distribution which produces data with
  //mean = 0; variance = 1.
  boost::normal_distribution<double> normal_dist(0,1);
  boost::variate_generator<base_generator_type&, boost::normal_distribution<double> > uni(generator, normal_dist);

  std::cout.setf(std::ios::fixed);
  // You can now retrieve random numbers from that distribution by means
  // of a STL Generator interface, i.e. calling the generator as a zero-
  // argument function.
  for(int i = 0; i < NUM_SAMPLES; i++) {
    base_generator_type tmpGenerator = generator;
    std::cout << generateRandom(tmpGenerator) << '\n';
  }


  return 0;
}
