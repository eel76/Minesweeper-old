#include "print.h"
#include "cells.h"
#include "filter.h"
#include "group.h"
#include "join.h"
#include "transform.h"
#include <iostream>
#include <string>

using namespace minesweeper;
using namespace std;

void minesweeper::print(std::string text)
{
  cout << text;
}

void minesweeper::print(Board board)
{
  for (auto row : groupRows(positions(board)))
    print(join(toStrings(cells(board) | at(get<Positions>(row)))) + "\n"s);
}

void minesweeper::printCountdown(Board board)
{
  auto countdown =
  size(cells(board) | deadly()) - size(cells(board) | is(Visibility::Recognized));
  print("Mines left: "s + to_string(countdown) + "\n"s);
}