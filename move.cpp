#include "move.h"
#include "print.h"
#include <iostream>
#include <regex>

using namespace std;
using namespace minesweeper;

namespace
{
template <class ValueType>
using Optional = pair<bool, ValueType>;

Optional<Position> RequestMove()
{
  string line;
  smatch match;

  Print("Your move (row, column): ");
  getline(cin, line);

  if (regex_match(line, match, regex{ " *([1-9]*[0-9]) *, *([1-9]*[0-9]) *" }))
    return{ true, { stoi(match[1]), stoi(match[2]) } };

  return{ false, {} };
}
bool IsValid(Board const& board, Position const& position)
{
  return board.count(position) && !get<Uncovered>(board.at(position));
}
}

Position minesweeper::PlayerMove(Board const& board)
{
  Optional<Position> move{};
  while (!get<bool>(move) || !IsValid(board, get<Position>(move)))
    move = RequestMove();

  return get<Position>(move);
}
