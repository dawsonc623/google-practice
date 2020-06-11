#ifndef EXERCISES__MAX_SPAN_H
#define EXERCISES__MAX_SPAN_H

#include <array>

#include "exercise.hpp"

class MaxSpan : public Exercise
{
public:
  MaxSpan();

  virtual void solve();

private:
  template <std::size_t N>
  void printSpan(std::array<int, N> nums, std::size_t prefixLength);

  template <std::size_t N>
  std::size_t getMaxSpan(std::array<int, N> nums);
};

#endif
