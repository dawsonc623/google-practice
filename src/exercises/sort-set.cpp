#include <array>
#include <iostream>
#include <set>
#include <vector>

#include "exercises/sort-set.hpp"

SortSet::SortSet() : Exercise(
                         "sortSet",
                         "Return an array that contains the sorted values from the input "
                         "array with duplicates removed.")
{
}

template <std::size_t N>
void SortSet::printSorted(std::array<int, N> nums, std::size_t prefixLength)
{
  // Set up the prefix
  std::string prefix(prefixLength, ' ');

  // Get the original array string
  std::string oldArrayString = arrayToString(nums);
  prefix.replace(0, oldArrayString.size(), oldArrayString);

  // Get the sorted array string
  std::string newArrayString = setToString(sort(nums));

  // Print it all
  std::cout << prefix << " => " << newArrayString << std::endl;
}

void SortSet::solve()
{
  printSorted<0>({}, 7);
  printSorted<1>({1}, 7);
  printSorted<2>({1, 1}, 7);
  printSorted<2>({1, 2}, 7);
  printSorted<3>({1, 2, 2}, 7);
  printSorted<3>({1, 2, 3}, 7);
  printSorted<3>({3, 2, 1}, 7);
  printSorted<3>({1, 3, 2}, 7);
  printSorted<3>({2, 2, 1}, 7);
  printSorted<2>({2, 1}, 7);
}

template <std::size_t N>
std::set<int> SortSet::sort(std::array<int, N> nums)
{
  return std::set<int>(nums.begin(), nums.end());
}
