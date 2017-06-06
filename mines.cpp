#include "mines.h"
#include "neighbors.h"
#include <algorithm>

using namespace minesweeper;
using namespace std;

Board minesweeper::uncoverMines(Board board)
{
  for (auto& cell : board)
    get<Uncovered>(get<State>(cell)) |= isMine(get<State>(cell));

  return board;
}

bool minesweeper::anyMineUncovered(Board board)
{
  return any_of(begin(board), end(board), [](auto cell) {
    return get<Uncovered>(get<State>(cell)) && isMine(get<State>(cell));
  });
}

bool minesweeper::allSafeUncovered(Board board)
{
  return all_of(begin(board), end(board), [](auto cell) {
    return get<Uncovered>(get<State>(cell)) || isMine(get<State>(cell));
  });
}
