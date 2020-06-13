#include <iostream>
#include <string>

#include "exercise.hpp"

Exercise::Exercise(std::string name, std::string problem) : name(name), problem(problem)
{
}

std::string Exercise::getName() const
{
  return name;
}

void Exercise::run()
{
  // Build the title decoration
  std::size_t nameSize = name.size();
  std::string titleBorder(nameSize + 4, '*');

  std::string title(titleBorder);
  title[1] = ' ';
  title[nameSize + 2] = ' ';
  title.replace(2, nameSize, name);

  // Print the title decoration
  std::cout << titleBorder << std::endl
            << title << std::endl
            << titleBorder << std::endl
            << std::endl;

  // Present the problem
  std::cout << "Problem: " << problem << std::endl
            << std::endl;

  // Run the solution
  solve();
}
