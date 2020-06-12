#include <array>
#include <iostream>
#include <limits>
#include <memory>
#include <string>

#include "exercise.hpp"
#include "exercises/max-span.hpp"
#include "exercises/string-splosion.hpp"
#include "exercises/sum-numbers-stream.hpp"
#include "exercises/without-string-regex.hpp"

// The number of exercises available to run
#define EXERCISE_COUNT 4

int main()
{
  // Create exercises
  std::array<std::unique_ptr<Exercise>, EXERCISE_COUNT> exercises{
      std::make_unique<MaxSpan>(),
      std::make_unique<StringSplosion>(),
      std::make_unique<SumNumbers>(),
      std::make_unique<WithoutStringRegex>()};

  // Show options to choose from
  for (short i = 0; i < EXERCISE_COUNT; i += 1)
  {
    std::cout << (i + 1) << ". " << exercises.at(i)->getName() << std::endl;
  }

  // Allow the user to exit the program via numeric input
  std::cout << (EXERCISE_COUNT + 1) << ". Exit" << std::endl;

  // Start with positive-case input
  std::cout << std::endl
            << "Choose an exercise to run: ";

  short exerciseNumber = 0;

  std::cin >> exerciseNumber;

  // Handle invalid input
  while (std::cin.fail() || exerciseNumber < 1 || exerciseNumber > EXERCISE_COUNT + 1)
  {
    // Skip bad input
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Prompt for valid input
    std::cout << "Invalid entry. Please enter a number from the above list: ";
    std::cin >> exerciseNumber;
  }

  // Spacing for readability
  std::cout << std::endl;

  // Check the input
  if (exerciseNumber <= EXERCISE_COUNT)
  {
    // Run the selected exercise if "Exit" was not selected
    exercises[exerciseNumber - 1]->run();
  }
  else
  {
    // Show an exit message so the user knows the program exited as expected
    std::cout << "Goodbye." << std::endl;
  }

  // Spacing for readability
  std::cout << std::endl;

  return 0;
}
