#pragma once
#include <utility>

namespace minesweeper
{
using Uncovered = bool;
using MineCount = int;
using State = std::pair<Uncovered, MineCount>;
}
