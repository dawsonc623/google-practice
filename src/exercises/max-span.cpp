#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

#include "exercises/max-span.hpp"

MaxSpan::MaxSpan() : Exercise(
                         "maxSpan",
                         "Consider the leftmost and righmost appearances of some value in an array. "
                         "We'll say that the \"span\" is the number of elements between the two inclusive. "
                         "A single value has a span of 1. Returns the largest span found in the given array.")
{
}

template <std::size_t N>
std::size_t MaxSpan::getMaxSpan(std::array<int, N> nums)
{
  // Set up data structures to support algorithm
  std::unordered_map<int, std::size_t> leftMostIndices;
  std::unordered_set<int> calculatedSpans;

  // Find the max span
  std::size_t theMaxSpan = 0;

  std::size_t numsSize = nums.size();

  if (numsSize > 0)
  {
    // Find the first index for each number
    for (std::size_t i = 0; i < numsSize; i += 1)
    {
      int num = nums[i];

      // If this is the first time we have seen this number
      if (leftMostIndices.find(num) == leftMostIndices.end())
      {
        // Save the index
        leftMostIndices[num] = i;
      }
    }

    // Find the last index for each number
    for (std::size_t i = 0; i < numsSize; i += 1)
    {
      // std::size_t is unsigned, so the typical (i = numSize - 1; i >= 0; i += 1) will not work
      std::size_t reverseI = numsSize - i - 1;

      int num = nums[reverseI];

      // If this is the first time we have seen this number
      if (calculatedSpans.find(num) == calculatedSpans.end())
      {
        // Calculate the span
        std::size_t span = reverseI - leftMostIndices[num] + 1;

        // Tell the algorithm we have seen this number now
        calculatedSpans.insert(num);

        // Update the max span if applicable
        if (span > theMaxSpan)
        {
          theMaxSpan = span;
        }
      }
    }
  }

  return theMaxSpan;
}

template <std::size_t N>
void MaxSpan::printSpan(std::array<int, N> nums, std::size_t prefixLength)
{
  // Set up the prefix
  std::string prefix(prefixLength, ' ');

  // Insert the array string
  std::string arrayString = arrayToString(nums);
  prefix.replace(0, arrayString.size(), arrayString);

  std::cout << prefix << " => " << getMaxSpan(nums) << std::endl;
}

void MaxSpan::solve()
{
  printSpan<5>({1, 2, 1, 1, 3}, 16);
  printSpan<7>({1, 4, 2, 1, 4, 1, 4}, 16);
  printSpan<7>({1, 4, 2, 1, 4, 4, 4}, 16);
  printSpan<3>({3, 3, 3}, 16);
  printSpan<3>({3, 9, 3}, 16);
  printSpan<3>({3, 9, 9}, 16);
  printSpan<2>({3, 9}, 16);
  printSpan<2>({3, 3}, 16);
  printSpan<0>({}, 16);
  printSpan<1>({1}, 16);
}
