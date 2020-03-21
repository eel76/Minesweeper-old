#include "move/mark.h"

#include "io/print.h"
#include "reveal.h"
#include "to_string.h"

using namespace std::string_literals;

auto minesweeper::move::mark(Position position) -> Move {
  return [=](auto board) {
    io::print("toggle mark "s + to_string(position) + "\n"s);
    return toggleMark(board, { Cell{ position, board[position] } });
  };
}
