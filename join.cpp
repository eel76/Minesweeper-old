#include "join.h"
#include <numeric>

using namespace minesweeper;
using namespace std;

Cells minesweeper::join(std::initializer_list<Cells> cellLists)
{
  auto joined = Cells{};

  for (auto cells : cellLists)
    joined.insert(end(joined), begin(cells), end(cells));

  return joined;
}

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