#include "move.h"
#include "print.h"
#include "reveal.h"
#include "to_string.h"

using namespace std::string_literals;

auto minesweeper::revealingMove(Position position) -> Move {
  return [=](auto board) {
    print("reveal "s + to_string(position) + "\n"s);
    return reveal(board, { Cell{ position, board[position] } });
  };
}

auto minesweeper::markingMove(Position position) -> Move {
  return [=](auto board) {
    print("toggle mark "s + to_string(position) + "\n"s);
    return toggleMark(board, { Cell{ position, board[position] } });
  };
}

auto minesweeper::unknownMove() -> Move {
  return [=](auto board) {
    print("Unknown move. Please enter again.\n"s);
    return board;
  };
}
