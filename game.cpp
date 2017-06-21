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

// enum struct GameState { Undecided, PlayerWon, PlayerLost };

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
  print("Your move ([m|mark] row column): "s);

  auto move = playerMove();
  return map<Action, Board>{
    { Action::ToggleMark, toggleMark(board, Positions{ get<Position>(move) }) },
    { Action::Uncover, uncover(board, Positions{ get<Position>(move) }) }
  }[get<Action>(move)];
}

#include <functional>
using Op = std::function<void()>;

void minesweeper::evaluateGame(Board board)
{
  auto correctedBoard = toggleMark(board, withMine(markedPositions(board), board));
  print(uncover(correctedBoard, deadlyPositions(board)));

  print(map<bool, string>{ { true, "You loose :-(\n"s } }[gameLost(board)]);
  print(map<bool, string>{ { true, "You win :-)\n"s } }[gameWon(board)]);
}