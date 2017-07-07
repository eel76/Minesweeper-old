#include "preparation.h"
#include "cells.h"
#include "combos.h"
#include "mine.h"

minesweeper::Board minesweeper::makeBoard(Dimensions dimensions, unsigned mineCount)
{
  auto board = Board{};

  for (auto position : allCombos(get<Rows>(dimensions), get<Columns>(dimensions)))
    board[position] = Threat(Visibility::Concealed, Severity::Negligible);

  return layMines(board, first(mineCount, toPositions(shuffle(cells(board)))));
}