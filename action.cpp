#include "action.h"

minesweeper::Action minesweeper::reveal()
{
  return { { Visibility::Concealed, Visibility::Revealed },
           { Visibility::Recognized, Visibility::Concealed },
           { Visibility::Revealed, Visibility::Revealed } };
}

minesweeper::Action minesweeper::changeGuess()
{
  return { { Visibility::Concealed, Visibility::Recognized },
           { Visibility::Recognized, Visibility::Concealed },
           { Visibility::Revealed, Visibility::Revealed } };
}