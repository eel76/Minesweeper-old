#pragma once
#include "board.h"
#include "cells.h"

namespace minesweeper {
  Board toggleMark(Board board, Cells cells);
  Board reveal(Board board, Cells cells);
}
