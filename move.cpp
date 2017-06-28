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

bool wrongMark(Board board, Position position)
{
  auto hints = neighbors(position) | within(board) | revealed(board);

  return !any_of(begin(hints), end(hints), [=](auto hint) {
    auto threatLevel = int(get<ThreatLevel>(board.at(hint)));
    return threatLevel == size(neighbors(hint) | within(board) | !revealed(board));
  });
}

Positions wrongMark(Board board)
{
  return positions(board) | marked(board) |
         [=](auto position) { return wrongMark(board, position); };
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

bool safeCells(Board board, Position position)
{
  auto hints = neighbors(position) | within(board) | revealed(board);

  return any_of(begin(hints), end(hints), [=](auto hint) {
    auto threatLevel = int(get<ThreatLevel>(board.at(hint)));
    return threatLevel == size(neighbors(hint) | within(board) | marked(board));
  });
}

Positions safeCells(Board board)
{
  return positions(board) | covered(board) |
         [=](auto position) { return safeCells(board, position); };
}

Move minesweeper::computerMove(Board board)
{
  auto moves = vector<Move>{};

  for (auto cell : join({ wrongMark(board), missingMark(board) }))
    moves.push_back({ Action::ToggleMark, cell });

  for (auto cell :
       join({ safeCells(board), sample(positions(board) | covered(board), 1) }))
    moves.push_back({ Action::Reveal, cell });

  return moves[0];
}