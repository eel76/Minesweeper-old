#include "computer.h"
#include "join.h"
#include "move.h"
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
    auto neighbors = cells(board) | neighborOf(get<Position>(cell));
    return size(neighbors | deadly()) == size(neighbors | !revealed());
  };
}

bool wrongMark(Board board, Position position)
{
  auto hints = cells(board) | neighborOf(position) | revealed();

  // FIXME: noneOf ?
  return !anyOf(hints, threatHidden(board));
}

Cells wrongMark(Board board)
{
  return cells(board) | recognized() |
         [=](auto cell) { return wrongMark(board, get<Position>(cell)); };
}

bool missingMark(Board board, Position position)
{
  auto hints = cells(board) | neighborOf(position) | revealed();
  return anyOf(hints, threatHidden(board));
}

Cells missingMark(Board board)
{
  return cells(board) | concealed() |
         [=](auto cell) { return missingMark(board, get<Position>(cell)); };
}

Test threatRecognized(Board board)
{
  return [=](auto cell) {
    auto neighbors = cells(board) | neighborOf(get<Position>(cell));
    return size(neighbors | deadly()) == size(neighbors | recognized());
  };
}

Test revealPossible(Board board)
{
  return [=](auto cell) {
    return anyOf(cells(board) | neighborOf(get<Position>(cell)) | revealed(),
                 threatRecognized(board));
  };
}

Cells revealPositions(Board board)
{
  auto concealedCells = shuffle(cells(board) | concealed());
  return join({ concealedCells | revealPossible(board), concealedCells });
}

Move minesweeper::computerMove(Board board)
{
  auto moves = vector<Move>{};

  for (auto cell : join({ wrongMark(board), missingMark(board) }))
    moves.push_back(toggle(get<Position>(cell)));

  for (auto cell : revealPositions(board))
    moves.push_back(reveal(get<Position>(cell)));

  return moves[0];
}