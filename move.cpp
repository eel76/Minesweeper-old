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

Move minesweeper::playerMove()
{
  return parseMove(inputLine());
}

bool anyOf(Positions positions, Predicate predicate)
{
  return any_of(begin(positions), end(positions), predicate);
}

Predicate threatHidden(Board board)
{
  return [=](auto hint) {
    auto threatLevel = int(get<Severity>(board.at(hint)));
    return threatLevel == size(neighbors(hint) | within(board) | !revealed(board));
  };
}

bool wrongMark(Board board, Position position)
{
  auto hints = neighbors(position) | within(board) | revealed(board);
  return !anyOf(hints, threatHidden(board));
}

Positions wrongMark(Board board)
{
  return positions(board) | recognized(board) |
         [=](auto position) { return wrongMark(board, position); };
}

bool missingMark(Board board, Position position)
{
  auto hints = neighbors(position) | within(board) | revealed(board);
  return anyOf(hints, threatHidden(board));
}

Positions missingMark(Board board)
{
  return positions(board) | covered(board) |
         [=](auto position) { return missingMark(board, position); };
}

Predicate threatMarked(Board board)
{
  return [=](auto position) {
    auto threatLevel = int(get<Severity>(board.at(position)));
    return threatLevel == size(neighbors(position) | within(board) | recognized(board));
  };
}

Predicate revealPossible(Board board)
{
  return [=](auto position) {
    return anyOf(neighbors(position) | within(board) | revealed(board), threatMarked(board));
  };
}

Positions revealPositions(Board board)
{
  return join({ positions(board) | covered(board) | revealPossible(board),
                sample(positions(board) | covered(board), 1) });
}

Move minesweeper::computerMove(Board board)
{
  auto moves = vector<Move>{};

  for (auto cell : join({ wrongMark(board), missingMark(board) }))
    moves.push_back({ Action::ChangeGuess, cell });

  for (auto cell : revealPositions(board))
    moves.push_back({ Action::Reveal, cell });

  return moves[0];
}