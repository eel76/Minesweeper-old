#include "input.h"
#include <iostream>

using namespace minesweeper;
using namespace std;

string minesweeper::inputLine()
{
  auto line = string{};
  getline(cin, line);

  return line;
}
