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

Positions wrongMark(Board /* board */)
{
  return {};
}

bool missingMark(Board board, Position position)
{
  auto hints = neighbors(position) | within(board) | revealed(board);

  return any_of(begin(hints), end(hints), [=](auto hint) {
    auto threatLevel = int(get<ThreatLevel>(board.at(hint)));
    return threatLevel == size(neighbors(hint) | within(board) | !revealed(board));
  });
}

Positions missingMark(Board board)
{
  return positions(board) | covered(board) |
         [=](auto position) { return missingMark(board, position); };
}

bool sureCell(Board board, Position position)
{
  auto hints = neighbors(position) | within(board) | revealed(board);

  return any_of(begin(hints), end(hints), [=](auto hint) {
    auto threatLevel = int(get<ThreatLevel>(board.at(hint)));
    return threatLevel == size(neighbors(hint) | within(board) | marked(board));
  });
}

Positions sureCell(Board board)
{
  auto candidates = positions(board) | covered(board);
  return { begin(candidates),
           remove_if(begin(candidates), end(candidates),
                     [=](auto candidate) { return !sureCell(board, candidate); }) };
}

Move minesweeper::computerMove(Board board)
{
  auto moves = vector<Move>{};

  for (auto cell : join({ wrongMark(board), missingMark(board) }))
    moves.push_back(Move{ Action::ToggleMark, cell });

  for (auto cell : join({ sureCell(board), sample(positions(board) | covered(board), 1) }))
    moves.push_back(Move{ Action::Uncover, cell });

  return moves[0];
}