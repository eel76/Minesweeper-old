#include "preparation.h"
#include "cells.h"
#include "combos.h"
#include "mine.h"

minesweeper::Board minesweeper::makeBoard()
{
  auto board = Board{};

  for (auto position : allCombos(9_rows, 9_columns))
    board[position] = Threat{};

  return layMines(board, first(10, toPositions(shuffle(cells(board)))));
}
