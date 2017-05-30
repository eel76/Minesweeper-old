#pragma once
#include <utility>

namespace minesweeper
{
  template <class ValueType>
  using Optional = std::pair<bool, ValueType>;
}
