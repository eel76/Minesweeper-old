#include "position.h"

using namespace std;
using namespace minesweeper;

Position minesweeper::operator+(Position const& first, Position const& second)
{
  return { get<0>(first) + get<0>(second), get<1>(first) + get<1>(second) };
}

bool minesweeper::operator<(Position const& first, Position const& second)
{
  return (get<0>(first) < get<0>(second)) && (get<1>(first) < get<1>(second));
}
