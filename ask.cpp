#include "ask.h"
#include "print.h"
#include <iostream>

using namespace std;

string minesweeper::ask(string question)
{
  print(question);

  auto line = string{};
  getline(cin, line);

  return line;
}