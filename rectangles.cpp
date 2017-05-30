#include "rectangles.h"
#include <algorithm>

using namespace std;
using namespace minesweeper;

bool minesweeper::MoveNonEmptyToFront(Rectangles::iterator begin, Rectangles::iterator end)
{
  return begin != partition(begin, end, [](auto const& rectangle) {
           return StrictlyLess(get<0>(rectangle), get<1>(rectangle));
         });
}
