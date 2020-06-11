#ifndef EXERCISE_HPP
#define EXERCISE_HPP

#include <string>

class Exercise
{
public:
  Exercise(
      std::string name,
      std::string problem);

  std::string getName() const;

  void run();

  virtual void solve() = 0;

private:
  std::string name;
  std::string problem;
};

#endif
