#include "move.h"
#include "input.h"
#include "parse.h"

using namespace minesweeper;

Move minesweeper::playerMove()
{
  return parseMove(inputLine());
}