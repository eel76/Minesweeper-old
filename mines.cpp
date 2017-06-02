#include "mines.h"
#include "neighbors.h"
#include <algorithm>

using namespace minesweeper;
using namespace std;

Board minesweeper::UncoverAllMines(Board board)
{
  for (auto& cell : board)
    get<Uncovered>(get<State>(cell)) |= IsMine(get<State>(cell));

  return board;
}

bool minesweeper::AnyMineUncovered(Board board)
{
  return any_of(begin(board), end(board), [](auto cell) {
    return get<Uncovered>(get<State>(cell)) && IsMine(get<State>(cell));
  });
}

bool minesweeper::AllSafeUncovered(Board board)
{
  return all_of(begin(board), end(board), [](auto cell) {
    return get<Uncovered>(get<State>(cell)) || IsMine(get<State>(cell));
  });
}
