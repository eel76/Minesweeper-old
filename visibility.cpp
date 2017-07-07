#include "visibility.h"
#include "action.h"

minesweeper::Visibility minesweeper::reveal(Visibility visibility)
{
  auto action = reveal();
  return action[visibility];
}

minesweeper::Visibility minesweeper::changeGuess(Visibility visibility)
{
  auto action = changeGuess();
  return action[visibility];
}