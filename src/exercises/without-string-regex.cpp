#include <iostream>
#include <regex>
#include <sstream>
#include <string>

#include "exercises/without-string-regex.hpp"

WithoutStringRegex::WithoutStringRegex() : Exercise(
                                               "withoutStringRegex",
                                               "Given two strings, `base` and `remove`, return a version of the base string where "
                                               "all instances of the remove string have been removed (not case sensitive). You may "
                                               "assume that the remove string is length 1 or more. Remove only non-overlapping instances, "
                                               "so with \"xxx\" removing \"xx\" leaves \"x\".")
{
}

void WithoutStringRegex::printWithoutString(std::string base, std::string remove, std::size_t prefixLength)
{
  // Set up the prefix
  std::string prefix(prefixLength, ' ');

  std::stringstream prefixContentStream;
  prefixContentStream << base << " - " << remove;

  std::string prefixContents = prefixContentStream.str();

  prefix.replace(0, prefixContents.size(), prefixContents);

  // Print result
  std::cout << prefix << " => " << withoutString(base, remove) << std::endl;
}

void WithoutStringRegex::solve()
{
  printWithoutString("Hello there", "llo", 19);
  printWithoutString("Hello there", "e", 19);
  printWithoutString("Hello there", "x", 19);
  printWithoutString("This is a FISH", "IS", 19);
  printWithoutString("THIS is a FISH", "is", 19);
  printWithoutString("THIS is a FISH", "iS", 19);
  printWithoutString("abxxxxab", "xx", 19);
  printWithoutString("abxxxab", "xx", 19);
  printWithoutString("abxxxab", "x", 19);
  printWithoutString("xxx", "x", 19);
  printWithoutString("xxx", "xx", 19);
  printWithoutString("xyzzy", "Y", 19);
  printWithoutString("", "x", 19);
  printWithoutString("abcabc", "b", 19);
  printWithoutString("AA22bb", "2", 19);
  printWithoutString("1111", "1", 19);
  printWithoutString("1111", "11", 19);
  printWithoutString("MkjtMkx", "Mk", 19);
  printWithoutString("Hi HoHo", "Ho", 19);
}

std::string WithoutStringRegex::withoutString(std::string base, std::string remove)
{
  std::regex removeRegex(remove, std::regex::icase);

  return std::regex_replace(base, removeRegex, "");
}
