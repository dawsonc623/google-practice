#ifndef EXERCISES__WITHOUT_STRING_REGEX_H
#define EXERCISES__WITHOUT_STRING_REGEX_H

#include <string>

#include "exercise.hpp"

class WithoutStringRegex : public Exercise
{
public:
  WithoutStringRegex();

  virtual void solve();

private:
  void printWithoutString(std::string base, std::string remove, std::size_t prefixLength);
  std::string withoutString(std::string base, std::string remove);
};

#endif
