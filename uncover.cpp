#include "uncover.h"
#include "filter.h"
#include "neighbors.h"

using namespace minesweeper;
using namespace std;

 Board minesweeper::uncover(Board board, Positions positions)
 {
   positions = coveredCells(withinBounds(positions, board), board);

   for (auto position : positions)
     get<Uncovered>(board[position]) = true;

   for (auto position : withoutMines(positions, board))
     board = uncover(board, add(neighbors(), position));

   return board;
 }
