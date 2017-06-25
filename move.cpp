#include "move.h"
#include "cells.h"
#include "filter.h"
#include "input.h"
#include "parse.h"
#include "positions.h"

using namespace minesweeper;

Move minesweeper::playerMove()
{
  return parseMove(inputLine());
}

Move minesweeper::computerMove(Board board)
{
  // falsche markierung entfernen
  // markierung setzen
  // sicheres feld aufdecken
  // zufälliges feld aufedecken

  auto positions = sample(coveredCells(allPositions(board), board), 1);
  return { Action::Uncover, positions[0] };
}