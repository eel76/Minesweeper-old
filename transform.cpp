#include "transform.h"
#include <algorithm>

using namespace minesweeper;
using namespace std;

std::vector<Cell> minesweeper::toCells(Positions positions, Board board)
{
  auto cells = std::vector<Cell>{};

  for (auto position : positions)
    cells.push_back(board[position]);

  return cells;
}

std::vector<std::string> minesweeper::toStrings(std::vector<Cell> cells)
{
  auto strings = std::vector<std::string>{ cells.size() };
  transform(begin(cells), end(cells), begin(strings), [](auto cell) {
    char cellCode[2][19] = { "##################", "XXXXXXXXX.12345678" };
    return string{ cellCode[get<State>(cell)][get<Mines>(cell) + 9] };
  });

  return strings;
}