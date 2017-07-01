#include "ask.h"
#include "print.h"
#include <iostream>

using namespace minesweeper;
using namespace std;

string minesweeper::ask(string question)
{
  print(question);

  auto answer = string{};
  getline(cin, answer);

  return answer;
}