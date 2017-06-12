#include "position.h"

using namespace minesweeper;
using namespace std;

Position minesweeper::operator+(Position first, Position second)
{
  return { get<0>(first) + get<0>(second), get<1>(first) + get<1>(second) };
}
