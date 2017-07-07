#pragma once

namespace minesweeper
{
  enum struct Visibility { Concealed, Recognized, Revealed };
  Visibility reveal(Visibility visibility);
  Visibility changeGuess(Visibility visibility);
}