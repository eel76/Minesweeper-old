#include "print.h"
#include <algorithm>
#include <iostream>

using namespace std;
using namespace minesweeper;

namespace
{
  auto Row(Board::const_iterator iterator)
  {
    return get<0>(get<Position const>(*iterator));
  }
  auto PrintRow(Board::const_iterator begin, Board::const_iterator end)
  {
    auto last = begin;
    while (begin != end && Row(last) == Row(begin))
      Print(get<State>(*(last = begin++)));

    Print("\n");
    return begin;
  }
}

void minesweeper::Print(Board const& board)
{
  auto row_end = begin(board);
  while (row_end != end(board))
    row_end = PrintRow(row_end, end(board));
}

void minesweeper::Print(State const& state)
{
  char constexpr kStateChar[2][19] = { "##################",
                                       "XXXXXXXXX.12345678" };

  Print({ kStateChar[get<Uncovered>(state)][get<MineCount>(state) + 9] });
}

void minesweeper::Print(std::string const& str)
{
  cout << str;
}
