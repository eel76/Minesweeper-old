#include "game.h"
#include "cells.h"
#include "filter.h"
#include "move.h"
#include "print.h"
#include "reveal.h"
#include <algorithm>

using namespace minesweeper;
using namespace std;

bool flagsGood(Board board)
{
  auto deadlyPositions = positions(board) | deadly(board);
  auto markedPositions = positions(board) | marked(board);

  return deadlyPositions == markedPositions;
}

bool flagsBad(Board board)
{
  auto deadlyPositions = positions(board) | deadly(board);
  auto markedPositions = positions(board) | marked(board);

  return size(markedPositions) >= size(deadlyPositions) && deadlyPositions != markedPositions;
}

// enum struct GameState { Undecided, PlayerWon, PlayerLost };

bool minesweeper::gameUndecided(Board board)
{
  return !gameLost(board) && !gameWon(board);
}

bool minesweeper::gameLost(Board board)
{
  return flagsBad(board) || any_of(begin(board), end(board), [](auto iterator) {
           return isRevealed(get<Threat>(iterator)) & isDeadly(get<Threat>(iterator));
         });
}

bool minesweeper::gameWon(Board board)
{
  return flagsGood(board) || all_of(begin(board), end(board), [](auto iterator) {
           return isRevealed(get<Threat>(iterator)) ^ isDeadly(get<Threat>(iterator));
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
  auto text = map<Action, string>{ { Action::Reveal, "reveal"s },
                                   { Action::ChangeGuess, "toggle mark"s } };

  print("Your move: "s + text[get<Action>(move)] + " "s);
  print(get<Position>(move));
  print("\n"s);
}

Board minesweeper::playRound(Board board, Player player)
{
  print(board);
  printCountdown(board);

  auto move = player(board);
  ::print(move);

  return map<Action, Board>{
    { Action::ChangeGuess, changeGuess(board, Positions{ get<Position>(move) }) },
    { Action::Reveal, reveal(board, Positions{ get<Position>(move) }) }
  }[get<Action>(move)];
}

void printIf(std::string text, bool condition)
{
  print(map<bool, string>{ { false, ""s }, { true, text } }[condition]);
}

void minesweeper::evaluateGame(Board board)
{
  auto correctedBoard =
  changeGuess(board, positions(board) | marked(board) | deadly(board));

  print(reveal(correctedBoard, positions(board) | deadly(board)));
  printIf("Game lost :-(\n"s, gameLost(board));
  printIf("Game won :-)\n"s, gameWon(board));
}