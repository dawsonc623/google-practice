#ifndef EXERCISES__STRING_SPLOSION_HPP
#define EXERCISES__STRING_SPLOSION_HPP

#include "exercise.hpp"

class StringSplosion : public Exercise
{
public:
  StringSplosion();

  virtual void solve();

private:
  std::string stringSplode(std::string str);
};

#endif
