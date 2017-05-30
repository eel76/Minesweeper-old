#include "input.h"
#include <iostream>

using namespace std;
using namespace minesweeper;

string minesweeper::InputLine()
{
  string line;
  getline(cin, line);

  return line;
}
