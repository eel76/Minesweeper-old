#pragma once
#include "cells.h"
#include "positions.h"
#include <initializer_list>
#include <string>

namespace minesweeper
{
  Cells join(std::initializer_list<Cells> cellLists);
  Positions join(std::vector<Positions> positionLists);
  std::string join(std::vector<std::string> strings);
}