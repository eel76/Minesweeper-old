#include "transform.h"

using namespace minesweeper;
using namespace std;

std::vector<Threat> minesweeper::toCells(Positions positions, Board board)
{
  auto cells = std::vector<Threat>{};

  for (auto position : positions)
    cells.push_back(board[position]);

  return cells;
}

std::vector<std::string> minesweeper::toStrings(std::vector<Threat> cells)
{
  auto strings = std::vector<std::string>{ cells.size() };

  for (auto cell : cells)
    strings.push_back(toString(cell));

  return strings;
}