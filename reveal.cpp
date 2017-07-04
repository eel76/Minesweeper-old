#include "reveal.h"
#include "cells.h"

using namespace minesweeper;
using namespace std;

Board minesweeper::changeGuess(Board board, Positions positions)
{
  for (auto cell : cells(board) | at(positions))
    board[get<Position>(cell)] = changeGuess(get<Threat>(cell));

  return board;
}

Board minesweeper::reveal(Board board, Positions positions)
{
  auto concealedCells = cells(board) | concealed() | at(positions);

  for (auto cell : concealedCells)
    board[get<Position>(cell)] = reveal(get<Threat>(cell));

  for (auto cell : concealedCells | safe())
    board = reveal(board, toPositions(cells(board) | neighborOf(get<Position>(cell))));

  return board;
}