#include "mines.h"
#include <algorithm>
#include "neighbors.h"

using namespace minesweeper;
using namespace std;

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
