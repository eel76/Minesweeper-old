#include "game.h"
#include "filter.h"
#include "cells.h"
#include "player.h"
#include "print.h"
#include "uncover.h"
#include <algorithm>

using namespace minesweeper;
using namespace std;

bool minesweeper::gameLost(Board board)
{
  return any_of(begin(board), end(board), [](auto cell) {
    return (get<State>(get<Cell>(cell)) == State::Uncovered) & isMine(get<Cell>(cell));
  });
}

bool minesweeper::gameWon(Board board)
{
  return all_of(begin(board), end(board), [](auto cell) {
    return (get<State>(get<Cell>(cell)) == State::Uncovered) ^ isMine(get<Cell>(cell));
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
  print(uncover(board, allMines(board)));

  if (gameLost(board))
    return print("You loose :-(\n");

  if (gameWon(board))
    return print("You win :-)\n");
}