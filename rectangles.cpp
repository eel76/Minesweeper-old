#include "rectangles.h"
#include <algorithm>

using namespace minesweeper;
using namespace std;

bool minesweeper::moveNonEmptyToFront(Rectangles::iterator begin, Rectangles::iterator end)
{
  return begin != partition(begin, end, [](auto const& rectangle) {
           return get<0>(rectangle) < get<1>(rectangle);
         });
}
