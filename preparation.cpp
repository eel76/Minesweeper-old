#include "preparation.h"
#include "cells.h"
#include "filter.h"
#include "mine.h"

using namespace minesweeper;
using namespace std;

Board minesweeper::makeBoard(Dimensions dimensions, unsigned mineCount)
{
  auto board = Board{};

  for (auto position : allCombos(get<Rows>(dimensions), get<Columns>(dimensions)))
    board[position] = Threat(Visibility::Concealed, Severity::Negligible);

  return layMines(board, sample(positions(board), mineCount));
}