#include "player.h"
#include "input.h"
#include "parse.h"

using namespace minesweeper;

Position minesweeper::playerMove()
{
  return parsePosition(inputLine());
}