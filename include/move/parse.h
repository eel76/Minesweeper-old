#pragma once
#include "move.h"

#include <string>

namespace minesweeper::move {
  auto parse(std::string text) -> Move;
}