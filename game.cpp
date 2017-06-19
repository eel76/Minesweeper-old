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
  auto flags = markedPositions(board);

  return mines == flags;
}

bool flagsBad(Board board)
{
  auto mines = minePositions(board);
  auto flags = markedPositions(board);

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
  printCountdown(board);
  print("Your move ([m|mark] row column): ");

  auto move = playerMove();
  if (get<Action>(move) == Action::ToggleMark)
    return toggleMark(board, Positions{ get<Position>(move) });

  return uncover(board, Positions{ get<Position>(move) });
}

void minesweeper::evaluateGame(Board board)
{
  auto correctedBoard = toggleMark(board, withMine(markedPositions(board), board));
  print(uncover(correctedBoard, minePositions(board)));

  if (gameLost(board))
    return print("You loose :-(\n");

  if (gameWon(board))
    return print("You win :-)\n");
}