#include "columns.h"
#include <algorithm>

using namespace minesweeper;
using namespace std;

Columns minesweeper::columns(unsigned count)
{
  auto columns = Columns(count);
  generate(begin(columns), end(columns),
           [=]() mutable { return Column(--count); });

  return columns;
}