#ifndef EXERCISE_HPP
#define EXERCISE_HPP

#include <array>
#include <sstream>
#include <string>
#include <unordered_map>

class Exercise
{
public:
  Exercise(
      std::string name,
      std::string problem);

  virtual ~Exercise() {}

  std::string getName() const;

  void run();

  virtual void solve() = 0;

protected:
  template <typename T, std::size_t N>
  std::string arrayToString(std::array<T, N> values);

  template <typename K, typename V>
  std::string mapToString(std::unordered_map<K, V> map);

private:
  std::string name;
  std::string problem;
};

template <typename T, std::size_t N>
std::string Exercise::arrayToString(std::array<T, N> values)
{
  std::stringstream arrayStream;

  arrayStream << '[';

  if (values.size() > 0)
  {
    for (std::size_t i = 0; i < N; i += 1)
    {
      arrayStream << values[i] << ",";
    }

    // Set up to overwrite the trailing comma
    arrayStream.seekp(-1, arrayStream.cur);
  }

  arrayStream << ']';

  return arrayStream.str();
}

template <typename K, typename V>
std::string Exercise::mapToString(std::unordered_map<K, V> map)
{
  std::stringstream mapStream;

  mapStream << "{";

  if (map.size() > 0)
  {
    for (auto &[key, value] : map)
    {
      mapStream << key << ":" << value << ",";
    }

    // Set up to overwrite the trailing comma
    mapStream.seekp(-1, mapStream.cur);
  }

  mapStream << "}";

  return mapStream.str();
}

#endif
