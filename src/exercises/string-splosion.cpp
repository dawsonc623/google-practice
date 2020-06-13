#include "exercises/string-splosion.hpp"

#include <iostream>
#include <sstream>

// Constructors

StringSplosion::StringSplosion() : Exercise(
                                       "stringSplosion",
                                       "Given a non-empty string like \"Code\" return a string like \"CCoCodCode\".")
{
}

// Methods

void StringSplosion::printSplosion(std::string str, std::size_t prefixLength)
{
  std::string prefix(prefixLength, ' ');
  prefix.replace(0, str.size(), str);

  std::cout << prefix << " => " << stringSplode(str) << std::endl;
}

void StringSplosion::solve()
{
  printSplosion("Code", 7);
  printSplosion("abc", 7);
  printSplosion("ab", 7);
  printSplosion("x", 7);
  printSplosion("fade", 7);
  printSplosion("There", 7);
  printSplosion("Kitten", 7);
  printSplosion("Bye", 7);
  printSplosion("Good", 7);
  printSplosion("Bad", 7);
  printSplosion("", 7);
}

std::string StringSplosion::stringSplode(std::string str)
{
  // Start with an empty stream (this will handle the empty string case as well)
  std::stringstream splosion;

  // Go through from 1 to size taking the segment from 0 to the current iteration
  std::size_t strSize = str.size();

  for (std::size_t i = 1; i <= strSize; i += 1)
  {
    // Tack the current segment on the end of the stream
    splosion << str.substr(0, i);
  }

  // Take the stream and convert it to a string
  return splosion.str();
}
