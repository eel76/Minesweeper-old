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

using Predicate = std::function<bool(Position)>;
Positions filter(Positions positions, Predicate predicate);

Positions wrongMark(Board /* board */)
{
  return {};
}

bool missingMark(Board board, Position position)
{
  auto uncoveredNeighbors =
  uncoveredCells(withinBounds(neighborPositions(position), board), board);

  return any_of(begin(uncoveredNeighbors), end(uncoveredNeighbors), [=](auto uncoveredNeighbor) {
    auto threatLevel = int(get<ThreatLevel>(board.at(uncoveredNeighbor)));
    return threatLevel ==
           coveredCells(withinBounds(neighborPositions(uncoveredNeighbor), board), board)
           .size();
  });
}

Positions missingMark(Board board)
{
  auto candidates = unmarkedCells(allPositions(board), board);
  return { begin(candidates), remove_if(begin(candidates), end(candidates), [=](auto candidate) {
             return !missingMark(board, candidate);
           }) };
}

bool sureCell(Board board, Position position)
{
  auto uncoveredNeighbors =
  uncoveredCells(withinBounds(neighborPositions(position), board), board);

  return any_of(begin(uncoveredNeighbors), end(uncoveredNeighbors), [=](auto uncoveredNeighbor) {
    auto threatLevel = int(get<ThreatLevel>(board.at(uncoveredNeighbor)));
    return threatLevel ==
           markedCells(withinBounds(neighborPositions(uncoveredNeighbor), board), board)
           .size();
  });
}

Positions sureCell(Board board)
{
  auto candidates = unmarkedCells(allPositions(board), board);
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
       join({ sureCell(board), sample(coveredCells(allPositions(board), board), 1) }))
    moves.push_back(Move{ Action::Uncover, cell });

  return moves[0];
}