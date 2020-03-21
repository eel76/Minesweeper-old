#pragma once
#include "getline.h"
#include "io/print.h"

namespace minesweeper {
  inline std::string askString(std::string const& question) {
    io::print(question);
    return getline();
  }
}
