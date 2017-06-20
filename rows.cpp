#include "rows.h"
#include <algorithm>

using namespace minesweeper;
using namespace std;

Rows minesweeper::rows(unsigned count)
{
  auto rows = Rows(count);
  generate(begin(rows), end(rows), [=]() mutable { return Row(--count); });

  return rows;
}