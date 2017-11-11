#include "print.h"
#include "deadly.h"
#include "group.h"
#include "marked.h"
#include "to_string.h"
#include <iostream>

using namespace std::string_literals;

void minesweeper::print(std::string const& text) {
  std::cout << text;
}

void minesweeper::print(Board board) {
  for (auto row : byRow(cells(board)))
    print(to_string(std::get<Cells>(row)) + "\n"s);
}

void minesweeper::printCountdown(Board board) {
  auto countdown = size(cells(board) | isDeadly()) - size(cells(board) | marked());
  print("Mines left: "s + std::to_string(countdown) + "\n"s);
}
