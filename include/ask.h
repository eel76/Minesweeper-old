#pragma once
#include "getline.h"
#include "print.h"

namespace minesweeper {
  inline std::string askString(std::string const& question) {
    print(question);
    return getline();
  }
}
