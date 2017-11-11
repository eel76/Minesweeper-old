#pragma once
#include "only.h"

namespace minesweeper {
  inline Filter isConcealed() {
    return only(State::Concealed);
  }
}
