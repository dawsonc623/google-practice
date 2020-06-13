#include <iostream>
#include <string>
#include <unordered_map>

#include "exercises/map-share.hpp"

MapShare::MapShare() : Exercise(
                           "mapShare",
                           "Modify and return the given map as follows: if the key \"a\" has a "
                           "value, set the key \"b\" to have that same value. In all cases remove "
                           "the key \"c\", leaving the rest of the map unchanged.")
{
}

template <typename K, typename V>
std::unordered_map<K, V> MapShare::changeMap(std::unordered_map<K, V> map)
{
  if (map.find("a") != map.end())
  {
    map["b"] = map["a"];
  }

  map.erase("c");

  return map;
}

template <typename K, typename V>
void MapShare::printMapChanges(std::unordered_map<K, V> map, std::size_t prefixLength)
{
  // Set up the prefix
  std::string prefix(prefixLength, ' ');

  // Get the original map string
  std::string originalMapString = mapToString(map);
  prefix.replace(0, originalMapString.size(), originalMapString);

  // Get the new map string
  std::string newMapString = mapToString(changeMap(map));

  // Print it all
  std::cout << prefix << " => " << newMapString << std::endl;
}

void MapShare::solve()
{
  printMapChanges<std::string, std::string>({{"a", "aaa"}, {"b", "bbb"}, {"c", "ccc"}}, 38);
  printMapChanges<std::string, std::string>({{"b", "xyz"}, {"c", "ccc"}}, 38);
  printMapChanges<std::string, std::string>({{"a", "aaa"}, {"c", "meh"}, {"d", "hi"}}, 38);
  printMapChanges<std::string, std::string>({{"a", "xyz"}, {"b", "1234"}, {"c", "yo"}, {"z", "zzz"}}, 38);
  printMapChanges<std::string, std::string>({{"a", "xyz"}, {"b", "1234"}, {"c", "yo"}, {"d", "ddd"}, {"e", "everything"}}, 38);
}
