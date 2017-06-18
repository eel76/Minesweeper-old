#include "game.h"
#include <algorithm>
#include "cells.h"
#include "filter.h"
#include "move.h"
#include "print.h"
#include "uncover.h"

using namespace minesweeper;
using namespace std;

bool flagsGood(Board board)
{
  auto mines = minePositions(board);
  auto flags = flaggedPositions(board);

  return mines == flags;
}

bool flagsBad(Board board)
{
  auto mines = minePositions(board);
  auto flags = flaggedPositions(board);

  return size(flags) >= size(mines) && mines != flags;
}

bool minesweeper::gameLost(Board board)
{
  return flagsBad(board) || any_of(begin(board), end(board), [](auto iterator) {
           return isUncovered(get<Cell>(iterator)) & containsMine(get<Cell>(iterator));
         });
}

bool minesweeper::gameWon(Board board)
{
  return flagsGood(board) || all_of(begin(board), end(board), [](auto iterator) {
           return isUncovered(get<Cell>(iterator)) ^ containsMine(get<Cell>(iterator));
         });
}

Board minesweeper::gameRound(Board board)
{
  print(board);
  printCounter(board);
  print("Your move (row, column): ");

  auto move = playerMove();
  if (get<Action>(move) == Action::ToggleFlag)
    return toggleFlag(board, Positions{ get<Position>(move) });

  return uncover(board, Positions{ get<Position>(move) });
}

void minesweeper::evaluateGame(Board board)
{
  auto correctedBoard = toggleFlag(board, withMine(flaggedPositions(board), board));
  print(uncover(correctedBoard, minePositions(board)));

  if (gameLost(board))
    return print("You loose :-(\n");

  if (gameWon(board))
    return print("You win :-)\n");
}