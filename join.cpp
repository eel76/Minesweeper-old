#include "join.h"
#include <numeric>

using namespace minesweeper;
using namespace std;

Positions minesweeper::join(std::vector<Positions> positionLists)
{
  auto joined = Positions{};

  for (auto positions : positionLists)
    joined.insert(end(joined), begin(positions), end(positions));

  return joined;
}

std::string minesweeper::join(std::vector<std::string> strings)
{
  return accumulate(begin(strings), end(strings), string(""));
}