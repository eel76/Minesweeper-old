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
  std::vector<State> toState(Positions positions, Board board)
  {
    auto states = std::vector<State>{};

    for (auto position : positions)
      states.push_back(board[position]);

    return states;
  }

  std::vector<std::string> toString(std::vector<State> states)
  {
    auto strings = std::vector<std::string>{ states.size() };
    transform(begin(states), end(states), begin(strings), [](auto state) {
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
