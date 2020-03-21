#include "move/reveal.h"

#include "io/print.h"
#include "reveal.h"
#include "to_string.h"

using namespace std::string_literals;

auto minesweeper::move::reveal(Position position) -> Move {
  return [=](auto board) {
    io::print("reveal "s + to_string(position) + "\n"s);
    return reveal(board, { Cell{ position, board[position] } });
  };
}
