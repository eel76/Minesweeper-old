#include "ask.h"
#include "getline.h"
#include "print.h"

std::string minesweeper::ask(std::string const& question) {
  print(question);
  return getline();
}
