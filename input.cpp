#include "input.h"
#include <iostream>

using namespace minesweeper;
using namespace std;

string minesweeper::InputLine()
{
  auto line = string{};
  getline(cin, line);

  return line;
}
