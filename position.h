#pragma once
#include <utility>

namespace minesweeper
{
using Position = std::pair<int, int>;
Position Add(Position const& first, Position const& second);
bool StrictlyLess(Position const& first, Position const& second);
}
