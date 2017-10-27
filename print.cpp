#include "print.h"
#include "cells.h"
#include "deadly.h"
#include "flagged.h"
#include "group.h"
#include "oneof.h"
#include "transform.h"
#include <iostream>
#include <string>

using namespace std::string_literals;

void minesweeper::print(std::string const& text) {
  std::cout << text;
}

void minesweeper::print(Board board) {
  for (auto row : byRow(toPositions(cells(board))))
    print(to_string(cells(board) | oneOf(std::get<Positions>(row))) + "\n"s);
}

void minesweeper::printCountdown(Board board) {
  auto countdown = size(cells(board) | deadly()) - size(cells(board) | marked());
  print("Mines left: "s + std::to_string(countdown) + "\n"s);
}
