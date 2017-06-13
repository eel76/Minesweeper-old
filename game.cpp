#include "game.h"
#include <algorithm>
#include "cells.h"
#include "filter.h"
#include "player.h"
#include "print.h"
#include "uncover.h"

using namespace minesweeper;
using namespace std;

bool isUncovered(Cell cell)
{
  return get<State>(cell) == State::Uncovered;
}

bool minesweeper::gameLost(Board board)
{
  return any_of(begin(board), end(board), [](auto cell) {
    return isUncovered(get<Cell>(cell)) & isMine(get<Cell>(cell));
  });
}

bool minesweeper::gameWon(Board board)
{
  return all_of(begin(board), end(board), [](auto cell) {
    return isUncovered(get<Cell>(cell)) ^ isMine(get<Cell>(cell));
  });
}

Board minesweeper::gameRound(Board board)
{
  print(board);
  print("Your move (row, column): ");

  return uncover(board, Positions{ playerMove() });
}

void minesweeper::evaluateGame(Board board)
{
  print(uncover(board, minePositions(board)));

  if (gameLost(board))
    return print("You loose :-(\n");

  if (gameWon(board))
    return print("You win :-)\n");
}