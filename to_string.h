#pragma once
#include "cells.h"
#include <string>

namespace minesweeper {
  std::string to_string(Mines severity);
  std::string to_string(Threat threat);
  std::string to_string(Cells cells);
  std::string to_string(Position position);
}
