#include "move.h"
#include "print.h"
#include "reveal.h"
#include "to_string.h"

using namespace std::string_literals;

auto minesweeper::revealingMove(Position position) -> Move {
  return [=](auto board) {
    print("reveal "s + to_string(position) + "\n"s);
    return revealed(board, { Cell{ position, board[position] } });
  };
}

auto minesweeper::markingMove(Position position) -> Move {
  return [=](auto board) {
    print("toggle mark "s + to_string(position) + "\n"s);
    return marked(board, { Cell{ position, board[position] } });
  };
}
