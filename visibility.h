#pragma once

namespace minesweeper
{
  enum Visibility { Concealed, Recognized, Revealed };
  Visibility reveal(Visibility visibility);
  Visibility changeGuess(Visibility visibility);
}