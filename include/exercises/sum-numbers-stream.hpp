#ifndef EXERCISES__SUM_NUMBERS_H
#define EXERCISES__SUM_NUMBERS_H

#include <string>

#include "exercise.hpp"

class SumNumbers : public Exercise
{
public:
  SumNumbers();

  virtual void solve();

private:
  int calculateSum(std::string input);
  void printSum(std::string input, std::size_t prefixLength);
};

#endif
