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
    board[position] = Cell(State::Covered, ThreatLevel::Minimal);

  return layMines(board, sample(positions(board), mineCount));
}