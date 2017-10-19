#include "game.h"
#include "cells.h"
#include "move.h"
#include "print.h"
#include "reveal.h"
#include <algorithm>

using namespace minesweeper;
using namespace std;

// enum struct GameState { Undecided, PlayerWon, PlayerLost };

bool minesweeper::gameUndecided(Board board)
{
  return !gameLost(board) && !gameWon(board);
}

bool minesweeper::gameLost(Board board)
{
  return any_of(begin(board), end(board), [](auto cell) {
    return isRevealed(get<Threat>(cell)) & isDeadly(get<Threat>(cell));
  });
}

bool minesweeper::gameWon(Board board)
{
  return all_of(begin(board), end(board), [](auto cell) {
    return isRevealed(get<Threat>(cell)) ^ isDeadly(get<Threat>(cell));
  });
}

Board minesweeper::playRound(Board board, Player player)
{
  print(board);
  printCountdown(board);

  auto move = player(board);
  return move(board);
}

void printIf(std::string const& text, bool condition)
{
  print(map<bool, string>{ { false, ""s }, { true, text } }[condition]);
}

void minesweeper::evaluateGame(Board board)
{
  print(reveal(board, toPositions(cells(board) | isDeadly())));
  printIf("Game lost :-(\n"s, gameLost(board));
  printIf("Game won :-)\n"s, gameWon(board));
}