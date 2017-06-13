#include "print.h"
#include <iostream>

using namespace minesweeper;
using namespace std;

void minesweeper::print(std::string s)
{
  cout << s;
}

#include <algorithm>
#include <numeric>
#include <vector>

#include "cells.h"
#include "positions.h"
#include "group.h"

namespace minesweeper
{
  std::vector<Cell> cellsFrom(Positions positions, Board board)
  {
    auto cells = std::vector<Cell>{};

    for (auto position : positions)
      cells.push_back(board[position]);

    return cells;
  }

  std::vector<std::string> stringsFrom(std::vector<Cell> cells)
  {
    auto strings = std::vector<std::string>{ cells.size() };
    transform(begin(cells), end(cells), begin(strings), [](auto cell) {
      char cellCode[2][19] = { "##################", "XXXXXXXXX.12345678" };
      return string{ cellCode[get<State>(cell)][get<Mines>(cell) + 9] };
    });

    return strings;
  }

  std::string join(std::vector<std::string> strings)
  {
    return accumulate(begin(strings), end(strings), string(""));
  }
}

void minesweeper::print(Board board)
{
  for (auto row : groupRows(allCells(board)))
    print(join(stringsFrom(cellsFrom(get<Positions>(row), board))) + "\n");
}