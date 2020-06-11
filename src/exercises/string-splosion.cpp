#include "exercises/string-splosion.hpp"

#include <iostream>
#include <sstream>

StringSplosion::StringSplosion() : Exercise(
                                       "stringSplosion",
                                       "Given a non-empty string like \"Code\" return a string like \"CCoCodCode\".")
{
}

void StringSplosion::solve()
{
  std::cout << "Code    => " << stringSplode("Code") << std::endl
            << "abc     => " << stringSplode("abc") << std::endl
            << "ab      => " << stringSplode("ab") << std::endl
            << "x       => " << stringSplode("x") << std::endl
            << "fade    => " << stringSplode("fade") << std::endl
            << "There   => " << stringSplode("There") << std::endl
            << "Kitten  => " << stringSplode("Kitten") << std::endl
            << "Bye     => " << stringSplode("Bye") << std::endl
            << "Good    => " << stringSplode("Good") << std::endl
            << "Bad     => " << stringSplode("Bad") << std::endl
            << "<emtpy> => " << stringSplode("") << std::endl;
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
