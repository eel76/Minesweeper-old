#include "print.h"
#include "cells.h"
#include "group.h"
#include "join.h"
#include "transform.h"
#include <iostream>

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