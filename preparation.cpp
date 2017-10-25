#include "preparation.h"
#include "cells.h"
#include "combos.h"
#include "concealed.h"
#include "deadly.h"
#include "mine.h"
#include "take.h"

using namespace minesweeper;

namespace {
  Board emptyBoard(Rows rows, Columns columns) {
    auto board = Board{};

    for (auto position : allCombos(rows, columns))
      board[position] = Threat{};

    return board;
  }

  Board layMines(Board board, unsigned count) {
    auto const candidates = cells(board) | concealed() | !isDeadly();
    return layMines(board, toPositions(shuffle(candidates) | take(count)));
  }
}

minesweeper::Board minesweeper::makeBoard() {
  return ::layMines(emptyBoard(10_rows, 10_columns), 10);
}
