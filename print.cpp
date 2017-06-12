#include "print.h"
#include <iostream>

using namespace minesweeper;
using namespace std;

namespace
{
  Position printCell(Board board, Position position)
  {
    char kStateChar[2][19] = { "##################", "XXXXXXXXX.12345678" };

    print({ kStateChar[get<Uncovered>(board[position])][get<Mines>(board[position]) + 9] });
    return position + Position{ 0, 1 };
  }

  Position printRow(Board board, Position position)
  {
    auto current = position;
    while (contains(board, current))
      current = printCell(board, current);

    print("\n");
    return position + Position{ 1, 0 };
  }
}

void minesweeper::print(std::string s)
{
  cout << s;
}

// void minesweeper::print(Board board)
// {
//   auto begin = Position{ 0, 0 };
//   while (contains(board, begin))
//     begin = printRow(board, begin);
// }

#include <algorithm>
#include <numeric>
#include <vector>

#include "cells.h"
#include "positions.h"

namespace minesweeper
{
  std::map<int, Positions> groupRows(Positions positions)
  {
    auto rows = std::map<int, Positions>{};

    for (auto position : positions)
      rows[get<0>(position)].push_back(position);

    return rows;
  }

  std::vector<State> toState(Positions positions, Board board)
  {
    auto states = std::vector<State>{ positions.size() };
    std::transform(begin(positions), end(positions), begin(states),
                   [=](auto position) { return board.at(position); });

    return states;
  }

  std::vector<std::string> toString(std::vector<State> states)
  {
    auto strings = std::vector<std::string>{ states.size() };
    std::transform(begin(states), end(states), begin(strings), [](auto state) {
      char stateChars[2][19] = { "##################", "XXXXXXXXX.12345678" };
      return string{ stateChars[get<Uncovered>(state)][get<Mines>(state) + 9] };
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
    print(join(toString(toState(get<Positions>(row), board))) + "\n");
}
