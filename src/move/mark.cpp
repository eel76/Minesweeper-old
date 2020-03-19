#include "move/mark.h"

#include "print.h"
#include "reveal.h"
#include "to_string.h"

using namespace std::string_literals;

auto minesweeper::move::mark(Position position) -> Move {
  return [=](auto board) {
    print("toggle mark "s + to_string(position) + "\n"s);
    return toggleMark(board, { Cell{ position, board[position] } });
  };
}
