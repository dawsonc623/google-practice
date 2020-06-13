#include <array>
#include <iostream>
#include <string>

#include "exercises/can-balance.hpp"

CanBalance::CanBalance() : Exercise(
                               "canBalance",
                               "Given a non-empty array, return true if there is a place to split the "
                               "array so that the sum of the numbers on one side is equal to the sum of "
                               "the numbers on the other side.")
{
}

template <std::size_t N>
bool CanBalance::checkBalancable(std::array<int, N> nums)
{
  std::size_t numsSize = nums.size();

  if (numsSize < 2)
  {
    return false;
  }

  // The sum of the numbers added from the start of the array forward
  int iSum = nums[0];

  // The sum of the numbers added from the end of the array backward
  int jSum = nums[numsSize - 1];

  int i = 1;
  int j = numsSize - 2;

  // Start at both ends of the array and calculate sums from each end until the indices meet
  while (i <= j)
  {
    // Add the next item in the array to the lowest sum. That is, if the sum from the front is
    // less than the sum from the back, take the next number from the front and add it to the
    // sum from the front. If the sum from the back is less than the sum from the front, add
    // to the back sum instead.
    if (iSum < jSum)
    {
      iSum += nums[i];
      i += 1;
    }
    else
    {
      jSum += nums[j];
      j -= 1;
    }
  }

  // Once the indices have met, check to see if the sums match
  return iSum == jSum;
}

template <std::size_t N>
void CanBalance::printBalancable(std::array<int, N> nums, std::size_t prefixLength)
{
  // Set up the prefix
  std::string prefix(prefixLength, ' ');

  // Insert the array string
  std::string arrayString = arrayToString(nums);
  prefix.replace(0, arrayString.size(), arrayString);

  std::cout << prefix << " => " << checkBalancable(nums) << std::endl;
}

void CanBalance::solve()
{
  printBalancable<5>({1, 1, 1, 2, 1}, 15);
  printBalancable<5>({2, 1, 1, 2, 1}, 15);
  printBalancable<2>({10, 10}, 15);
  printBalancable<5>({10, 0, 1, -1, 10}, 15);
  printBalancable<5>({1, 1, 1, 1, 4}, 15);
  printBalancable<5>({2, 1, 1, 1, 4}, 15);
  printBalancable<5>({2, 3, 4, 1, 2}, 15);
  printBalancable<7>({1, 2, 3, 1, 0, 2, 3}, 15);
  printBalancable<7>({1, 2, 3, 1, 0, 1, 3}, 15);
  printBalancable<1>({1}, 15);
  printBalancable<5>({1, 1, 1, 2, 1}, 15);
}
