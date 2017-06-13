#include "preparation.h"
#include "cells.h"
#include "filter.h"
#include "neighbors.h"

#include <algorithm>
#include <numeric>

using namespace minesweeper;
using namespace std;

namespace minesweeper
{
  std::vector<int> ints(size_t count)
  {
    auto ints = std::vector<int>(count);
    iota(begin(ints), end(ints), 0);

    return ints;
  }

  std::vector<std::pair<int, int>> zipWith(Rows rows, int column)
  {
    auto positions = Positions{};

    for (auto row : rows)
      positions.push_back({ row, column });

    return positions;
  }

  Positions join(std::vector<Positions> positionRanges)
  {
    auto joined = Positions{};

    for (auto positions : positionRanges)
      joined.insert(end(joined), begin(positions), end(positions));

    return joined;
  }

  std::vector<std::pair<int, int>> cartesianProduct(Rows rows, Columns columns)
  {
    auto positionRanges = std::vector<Positions>{};

    for (auto column : columns)
      positionRanges.push_back(zipWith(rows, column));

    return join(positionRanges);
  }
}

Board layMine(Board board, Position position)
{
  for (auto neighbor : withinBounds(neighbors(position), board))
    get<Mines>(board[neighbor]) += 1;

  get<Mines>(board[position]) -= 9;
  return board;
}

Board minesweeper::prepareBoard(Size size, MineCount mineCount)
{
  auto board = Board{};

  for (auto position : cartesianProduct(get<0>(size), get<1>(size)))
    board[position] = {};

  for (auto position : sample(allCells(board), mineCount))
    board = layMine(board, position);

  return board;
}
