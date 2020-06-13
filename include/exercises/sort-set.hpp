#ifndef EXERCISES__SORT_H
#define EXERCISES__SORT_H

#include <array>

#include "exercise.hpp"

class SortSet : public Exercise
{
public:
  SortSet();

  virtual void solve();

private:
  template <std::size_t N>
  void printSorted(std::array<int, N> nums, std::size_t prefixLength);

  template <std::size_t N>
  std::set<int> sort(std::array<int, N> nums);
};

#endif
