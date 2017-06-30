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
  auto deadlyCells     = cells(board) | deadly();
  auto recognizedCells = cells(board) | is(Visibility::Recognized);

  // FIXME: use equal()
  return deadlyCells == recognizedCells;
}

bool flagsBad(Board board)
{
  auto deadlyCells     = cells(board) | deadly();
  auto recognizedCells = cells(board) | is(Visibility::Recognized);

  // FIXME: use equal()
  return size(recognizedCells) >= size(deadlyCells) && deadlyCells != recognizedCells;
}

// enum struct GameState { Undecided, PlayerWon, PlayerLost };

bool minesweeper::gameUndecided(Board board)
{
  return !gameLost(board) && !gameWon(board);
}

bool minesweeper::gameLost(Board board)
{
  return flagsBad(board) || any_of(begin(board), end(board), [](auto cell) {
           return isRevealed(get<Threat>(cell)) & isDeadly(get<Threat>(cell));
         });
}

bool minesweeper::gameWon(Board board)
{
  return flagsGood(board) || all_of(begin(board), end(board), [](auto cell) {
           return isRevealed(get<Threat>(cell)) ^ isDeadly(get<Threat>(cell));
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
    { Action::ChangeGuess, changeGuess(board, { get<Position>(move) }) },
    { Action::Reveal, reveal(board, { get<Position>(move) }) }
  }[get<Action>(move)];
}

void printIf(std::string text, bool condition)
{
  print(map<bool, string>{ { false, ""s }, { true, text } }[condition]);
}

void minesweeper::evaluateGame(Board board)
{
  auto correctedBoard =
  changeGuess(board, positions(board) | recognized(board) | deadly(board));

  print(reveal(correctedBoard, positions(board) | deadly(board)));
  printIf("Game lost :-(\n"s, gameLost(board));
  printIf("Game won :-)\n"s, gameWon(board));
}