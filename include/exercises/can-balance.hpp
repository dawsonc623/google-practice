#ifndef EXERCISES__CAN_BALANCE_H
#define EXERCISES__CAN_BALANCE_H

#include <array>

#include "exercise.hpp"

class CanBalance : public Exercise
{
public:
  CanBalance();

  virtual void solve();

private:
  template <std::size_t N>
  bool checkBalancable(std::array<int, N> nums);

  template <std::size_t N>
  void printBalancable(std::array<int, N> nums, std::size_t prefixLength);
};

#endif
