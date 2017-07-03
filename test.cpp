#include "test.h"

using namespace minesweeper;
using namespace std;

Test minesweeper::operator!(Test test)
{
  return [=](auto cell) { return !test(cell); };
}