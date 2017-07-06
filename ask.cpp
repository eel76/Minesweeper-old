#include "ask.h"
#include "print.h"
#include <iostream>

std::string minesweeper::ask(std::string question)
{
  print(question);

  auto answer = std::string{};
  getline(std::cin, answer);

  return answer;
}