#include "print.h"
#include <algorithm>
#include <iostream>

using namespace minesweeper;
using namespace std;

namespace
{
  auto Row(Board::iterator iterator)
  {
    return get<0>(get<Position const>(*iterator));
  }
  auto PrintRow(Board::iterator begin, Board::iterator end)
  {
    auto last = begin;
    while (begin != end && Row(last) == Row(begin))
      print(get<State>(*(last = begin++)));

    print("\n");
    return begin;
  }
}

void minesweeper::print(Board board)
{
  auto row_end = begin(board);
  while (row_end != end(board))
    row_end = PrintRow(row_end, end(board));
}

void minesweeper::print(State state)
{
  char constexpr kStateChar[2][19] = { "##################",
                                       "XXXXXXXXX.12345678" };

  print({ kStateChar[get<Uncovered>(state)][get<Mines>(state) + 9] });
}

void minesweeper::print(std::string s)
{
  cout << s;
}
