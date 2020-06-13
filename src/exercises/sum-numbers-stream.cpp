#include <iostream>
#include <sstream>
#include <string>

#include "exercises/sum-numbers-stream.hpp"

SumNumbers::SumNumbers() : Exercise(
                               "sumNumbers",
                               "Given a string, return the sum of the numbers appearing in the string, "
                               "ignoring all other characters. A number is a series of 1 or more digit "
                               "chars in a row.")
{
}

int SumNumbers::calculateSum(std::string input)
{
  // Use a stream to extract integers
  std::istringstream inputStream(input);

  int sum = 0;

  // Loop to the end of the string
  while (!inputStream.eof())
  {
    // Try to read an integer
    int num;
    inputStream >> num;

    // Check if reading was successful
    if (!inputStream.fail())
    {
      // If so, add the integer to the sum
      sum += num;
    }
    else
    {
      // If not, skip the current character and try again
      inputStream.clear();
      inputStream.ignore(1);
    }
  }

  return sum;
}

void SumNumbers::printSum(std::string input, std::size_t prefixLength)
{
  std::string prefix(prefixLength, ' ');
  prefix.replace(0, input.size(), input);

  std::cout << prefix << " => " << calculateSum(input) << std::endl;
}

void SumNumbers::solve()
{
  printSum("abc123xyz", 9);
  printSum("aa11b33", 9);
  printSum("7 11", 9);
  printSum("Chocolate", 9);
  printSum("5hoco1a1e", 9);
  printSum("5$$1;;1!!", 9);
  printSum("a1234bb11", 9);
  printSum("", 9);
  printSum("a22bbb3", 9);
}
