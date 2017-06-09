#include "print.h"
#include <iostream>

using namespace minesweeper;
using namespace std;

namespace
{
  Position printCell(Board board, Position position)
  {
    char kStateChar[2][19] = { "##################", "XXXXXXXXX.12345678" };

    print({ kStateChar[get<Uncovered>(board[position])][get<Mines>(board[position]) + 9] });
    return position + Position{ 0, 1 };
  }

  Position printRow(Board board, Position position)
  {
    auto current = position;
    while (contains(board, current))
      current = printCell(board, current);

    print("\n");
    return position + Position{ 1, 0 };
  }
}

void minesweeper::print(std::string s)
{
  cout << s;
}

void minesweeper::print(Board board)
{
  auto begin = Position{ 0, 0 };
  while (contains(board, begin))
    begin = printRow(board, begin);
}
