#ifndef EXERCISES__MAP_SHARE_H
#define EXERCISES__MAP_SHARE_H

#include <unordered_map>

#include "exercise.hpp"

class MapShare : public Exercise
{
public:
  MapShare();

  virtual void solve();

private:
  template <typename K, typename V>
  std::unordered_map<K, V> changeMap(std::unordered_map<K, V> map);

  template <typename K, typename V>
  void printMapChanges(std::unordered_map<K, V> map, std::size_t prefixLength);
};

#endif
