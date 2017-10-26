#pragma once
#include "getline.h"
#include "print.h"

namespace minesweeper {
  inline std::string ask(std::string const& question) {
    print(question);
    return getline();
  }
}
