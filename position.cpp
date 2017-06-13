#include "position.h"

using namespace minesweeper;
using namespace std;

Position minesweeper::operator+(Position first, Position second)
{
  return { get<Row>(first) + get<Row>(second), get<Column>(first) + get<Column>(second) };
}