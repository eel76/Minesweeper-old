#include "move.h"
#include "print.h"
#include "reveal.h"

using namespace minesweeper;
using namespace std;

namespace minesweeper
{
  std::string to_string(Position position)
  {
    return to_string(get<Row>(position)) + ", "s + to_string(get<Column>(position));
  }
}

Move minesweeper::reveal(Position position)
{
  return [=](auto board) {
    print("Reveal "s + to_string(position) + "\n"s);
    return reveal(board, { position });
  };
}

Move minesweeper::toggle(Position position)
{
  return [=](auto board) {
    print("Toggle "s + to_string(position) + "\n"s);
    return changeGuess(board, { position });
  };
}