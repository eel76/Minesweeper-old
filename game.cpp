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

void print(Position position)
{
  print(to_string(int(get<Row>(position))));
  print(", "s);
  print(to_string(int(get<Column>(position))));
}

void print(Move move)
{
  auto text = map<Action, string>{ { Action::Uncover, "uncover"s },
                                   { Action::ToggleMark, "mark"s } };

  print("Your move: "s + text[get<Action>(move)] + " "s);
  print(get<Position>(move));
  print("\n"s);
}

Board minesweeper::gameRound(Board board)
{
  print(board);
  printCountdown(board);
  // print("Your move ([m|mark] row column): "s);

  auto move = computerMove(board);
  ::print(move);

  return map<Action, Board>{
    { Action::ToggleMark, toggleMark(board, Positions{ get<Position>(move) }) },
    { Action::Uncover, uncover(board, Positions{ get<Position>(move) }) }
  }[get<Action>(move)];
}

void printIf(std::string text, bool condition)
{
  print(map<bool, string>{ { false, ""s }, { true, text } }[condition]);
}

void minesweeper::evaluateGame(Board board)
{
  auto correctedBoard = toggleMark(board, withMine(markedPositions(board), board));

  print(uncover(correctedBoard, deadlyPositions(board)));
  printIf("You loose :-(\n"s, gameLost(board));
  printIf("You win :-)\n"s, gameWon(board));
}