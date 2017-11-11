#pragma once
#include "board.h"
#include "cells.h"

namespace minesweeper {
  Board marked(Board board, Cells cells);
  Board revealed(Board board, Cells cells);
}
