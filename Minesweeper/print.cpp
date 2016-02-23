#include "print.h"
#include <algorithm>
#include <iostream>

using namespace std;

namespace minesweeper
{
namespace
{
char const kStateChar[2][19] = { "##################", "XXXXXXXXX.12345678" };

string ToString(State const& state)
{
  return{ kStateChar[get<Uncovered>(state)][get<MineCount>(state) + 9] };
}
void PrintLine(pair<Board::const_iterator, Board::const_iterator> range)
{
  for_each(get<0>(range), get<1>(range), [](auto const& cell)
  {
    Print(ToString(get<State>(cell)));
  });
  Print("\n");
}
auto FirstRow(Board::const_iterator begin, Board::const_iterator end)
{
  auto const first_row = get<0>(get<Position const>(*begin));
  return make_pair(begin, find_if_not(begin, end, [=](auto const& cell)
  {
    return get<0>(get<Position const>(cell)) == first_row;
  }));
}
}

void Print(Board const& board)
{
  auto row = make_pair(begin(board), begin(board));
  while (get<1>(row) != end(board))
    PrintLine(row = FirstRow(get<1>(row), end(board)));
}
void Print(std::string const& str)
{
  cout << str;
}
}
