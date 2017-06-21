#include "game.h"
#include "cells.h"
#include "filter.h"
#include "move.h"
#include "print.h"
#include "uncover.h"
#include <algorithm>

using namespace minesweeper;
using namespace std;

bool flagsGood(Board board)
{
  auto deadly = deadlyPositions(board);
  auto marked = markedPositions(board);

  return deadly == marked;
}

bool flagsBad(Board board)
{
  auto deadly = deadlyPositions(board);
  auto marked = markedPositions(board);

  return size(marked) >= size(deadly) && deadly != marked;
}

bool minesweeper::gameLost(Board board)
{
  return flagsBad(board) || any_of(begin(board), end(board), [](auto iterator) {
           return isUncovered(get<Cell>(iterator)) & isDeadly(get<Cell>(iterator));
         });
}

bool minesweeper::gameWon(Board board)
{
  return flagsGood(board) || all_of(begin(board), end(board), [](auto iterator) {
           return isUncovered(get<Cell>(iterator)) ^ isDeadly(get<Cell>(iterator));
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
  print(uncover(correctedBoard, deadlyPositions(board)));

  if (gameLost(board))
    return print("You loose :-(\n");

  if (gameWon(board))
    return print("You win :-)\n");
}