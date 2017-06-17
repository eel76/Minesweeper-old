#include "game.h"
#include <algorithm>
#include "cells.h"
#include "filter.h"
#include "move.h"
#include "print.h"
#include "uncover.h"

using namespace minesweeper;
using namespace std;

bool minesweeper::gameLost(Board board)
{
  return any_of(begin(board), end(board), [](auto cell) {
    return isUncovered(get<Cell>(cell)) & containsMine(get<Cell>(cell));
  });
}

bool minesweeper::gameWon(Board board)
{
  return all_of(begin(board), end(board), [](auto cell) {
    return isUncovered(get<Cell>(cell)) ^ containsMine(get<Cell>(cell));
  });
}

Board minesweeper::gameRound(Board board)
{
  print(board);
  print("Your move (row, column): ");

  auto move = playerMove();
  if (get<Action>(move) == Action::ToggleFlag)
    return toggleFlag(board, get<Position>(move));

  return uncover(board, Positions{ get<Position>(move) });
}

void minesweeper::evaluateGame(Board board)
{
  print(uncover(board, minePositions(board)));

  if (gameLost(board))
    return print("You loose :-(\n");

  if (gameWon(board))
    return print("You win :-)\n");
}