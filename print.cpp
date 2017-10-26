#include "print.h"
#include "cells.h"
#include "deadly.h"
#include "flagged.h"
#include "group.h"
#include "join.h"
#include "oneof.h"
#include "transform.h"
#include <iostream>
#include <string>

using namespace minesweeper;
using namespace std;

void minesweeper::print(std::string const& text) {
  cout << text;
}

void minesweeper::print(Board board) {
  for (auto row : byRow(toPositions(cells(board))))
    print(join(toString(cells(board) | oneOf(get<Positions>(row)))) + "\n"s);
}

void minesweeper::printCountdown(Board board) {
  auto countdown = size(cells(board) | deadly()) - size(cells(board) | flagged());
  print("Mines left: "s + std::to_string(countdown) + "\n"s);
}
