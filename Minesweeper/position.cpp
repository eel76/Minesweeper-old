#include "position.h"

using namespace std;

namespace minesweeper
{
Position Add(Position const& first, Position const& second)
{
  return{ get<0>(first) + get<0>(second), get<1>(first) + get<1>(second) };
}
bool StrictlyLess(Position const& first, Position const& second)
{
  return (get<0>(first) < get<0>(second)) && (get<1>(first) < get<1>(second));
}
}
