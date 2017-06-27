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
  auto uncoveredNeighbors = neighborPositions(position) | within(board) | uncovered(board);

  return any_of(begin(uncoveredNeighbors), end(uncoveredNeighbors), [=](auto uncoveredNeighbor) {
    auto threatLevel = int(get<ThreatLevel>(board.at(uncoveredNeighbor)));
    return threatLevel == size(neighborPositions(uncoveredNeighbor) |
                               within(board) | covered(board));
  });
}

Positions missingMark(Board board)
{
  return allPositions(board) | covered(board) |
         [=](auto position) { return missingMark(board, position); };
}

bool sureCell(Board board, Position position)
{
  auto uncoveredNeighbors = neighborPositions(position) | within(board) | uncovered(board);

  return any_of(begin(uncoveredNeighbors), end(uncoveredNeighbors), [=](auto uncoveredNeighbor) {
    auto threatLevel = int(get<ThreatLevel>(board.at(uncoveredNeighbor)));
    return threatLevel == size(neighborPositions(uncoveredNeighbor) |
                               within(board) | marked(board));
  });
}

Positions sureCell(Board board)
{
  auto candidates = allPositions(board) | covered(board);
  return { begin(candidates),
           remove_if(begin(candidates), end(candidates),
                     [=](auto candidate) { return !sureCell(board, candidate); }) };
}

Move minesweeper::computerMove(Board board)
{
  auto moves = vector<Move>{};

  for (auto cell : join({ wrongMark(board), missingMark(board) }))
    moves.push_back(Move{ Action::ToggleMark, cell });

  for (auto cell :
       join({ sureCell(board), sample(allPositions(board) | covered(board), 1) }))
    moves.push_back(Move{ Action::Uncover, cell });

  return moves[0];
}