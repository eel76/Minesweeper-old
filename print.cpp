#include "print.h"
#include <iostream>
#include <string>
#include "cells.h"
#include "group.h"
#include "join.h"
#include "transform.h"

using namespace minesweeper;
using namespace std;

void minesweeper::print(std::string s)
{
  cout << s;
}

void minesweeper::print(Board board)
{
  for (auto row : groupRows(allPositions(board)))
    print(join(toStrings(toCells(get<Positions>(row), board))) + "\n");
}

void minesweeper::printCountdown(Board board)
{
  auto minesLeft = size(minePositions(board)) - size(markedPositions(board));
  print("Mines left: " + to_string(minesLeft) + "\n");
}