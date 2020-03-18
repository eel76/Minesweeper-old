#pragma once
#include "cells.h"
#include <map>

namespace minesweeper {
  std::map<Row, Cells> byRow(Cells cells);
}
