#include "move.h"
#include "cells.h"
#include "filter.h"
#include "input.h"
#include "join.h"
#include "neighbors.h"
#include "parse.h"
#include "positions.h"
#include <algorithm>
#include <functional>
#include <iostream>

using namespace minesweeper;
using namespace std;

bool anyOf(Cells cells, Test test)
{
  return any_of(begin(cells), end(cells), test);
}

Test threatHidden(Board board)
{
  return [=](auto cell) {
    auto severity = int(get<Severity>(get<Threat>(cell)));
    return severity == size(cells(board) | at(neighbors(get<Position>(cell))) |
                            !is(Visibility::Revealed));
  };
}

bool wrongMark(Board board, Position position)
{
  auto hints = cells(board) | at(neighbors(position)) | is(Visibility::Revealed);

  // FIXME: noneOf ?
  return !anyOf(hints, threatHidden(board));
}

Cells wrongMark(Board board)
{
  return cells(board) | is(Visibility::Recognized) |
         [=](auto cell) { return wrongMark(board, get<Position>(cell)); };
}

bool missingMark(Board board, Position position)
{
  auto hints = cells(board) | at(neighbors(position)) | is(Visibility::Revealed);
  return anyOf(hints, threatHidden(board));
}

Cells missingMark(Board board)
{
  return cells(board) | is(Visibility::Concealed) |
         [=](auto cell) { return missingMark(board, get<Position>(cell)); };
}

Test threatRecognized(Board board)
{
  return [=](auto cell) {
    auto severity = int(get<Severity>(get<Threat>(cell)));
    return severity == size(cells(board) | at(neighbors(get<Position>(cell))) |
                            is(Visibility::Recognized));
  };
}

Test revealPossible(Board board)
{
  return [=](auto cell) {
    return anyOf(cells(board) | at(neighbors(get<Position>(cell))) | is(Visibility::Revealed),
                 threatRecognized(board));
  };
}

#include <random>

Cells shuffle(Cells cells)
{
  shuffle(begin(cells), end(cells), ranlux48{ random_device{}() });
  return cells;
}

Cells revealPositions(Board board)
{
  auto concealedCells = shuffle(cells(board) | is(Visibility::Concealed));
  return join({ concealedCells | revealPossible(board), concealedCells });
}

Move minesweeper::computerMove(Board board)
{
  auto moves = vector<Move>{};

  for (auto cell : join({ wrongMark(board), missingMark(board) }))
    moves.push_back({ Action::ChangeGuess, get<Position>(cell) });

  for (auto cell : revealPositions(board))
    moves.push_back({ Action::Reveal, get<Position>(cell) });

  return moves[0];
}