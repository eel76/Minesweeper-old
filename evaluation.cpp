#include "evaluation.h"
#include <algorithm>

using namespace std;

bool minesweeper::gameLost(Board board)
{
  return any_of(begin(board), end(board), [](auto cell) {
    return get<Uncovered>(get<State>(cell)) & isMine(get<State>(cell));
  });
}

bool minesweeper::gameWon(Board board)
{
  return all_of(begin(board), end(board), [](auto cell) {
    return get<Uncovered>(get<State>(cell)) ^ isMine(get<State>(cell));
  });
}
