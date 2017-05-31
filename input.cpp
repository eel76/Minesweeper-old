#include "input.h"
#include <iostream>

using namespace std;
using namespace minesweeper;

string minesweeper::InputLine()
{
  auto line = string{};
  getline(cin, line);

  return line;
}
