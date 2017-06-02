#include "mines.h"
#include <algorithm>
#include <functional>
#include "neighbors.h"

using namespace std;
using namespace std::placeholders;
using namespace minesweeper;

Board minesweeper::LayMines(Board board, MineCount mineCount)
{
  auto const adjust_mine_count = [&](auto const& position, auto value) {
    get<Mines>(board.at(position)) += value;
  };

  for (auto const& position : RandomPositions(board, mineCount))
  {
    auto const neighbors = Neighbors(board, position);
    for_each(begin(neighbors), end(neighbors), bind(adjust_mine_count, _1, +1));
    adjust_mine_count(position, -9);
  }

  return board;
}

Board minesweeper::UncoverAllMines(Board board)
{
  for (auto& cell : board)
    get<Uncovered>(get<State>(cell)) |= IsMine(get<State>(cell));

  return board;
}

bool minesweeper::AnyMineUncovered(Board const& board)
{
  return any_of(begin(board), end(board), [](auto const& cell) {
    auto const& state = get<State>(cell);
    return get<Uncovered>(state) && IsMine(state);
  });
}

bool minesweeper::AllSafeUncovered(Board const& board)
{
  return all_of(begin(board), end(board), [](auto const& cell) {
    auto const& state = get<State>(cell);
    return get<Uncovered>(state) || IsMine(state);
  });
}
