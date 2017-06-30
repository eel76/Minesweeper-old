#include "visibility.h"
#include <map>

using namespace minesweeper;
using namespace std;

Visibility minesweeper::reveal(Visibility visibility)
{
  return map<Visibility, Visibility>{ { Visibility::Concealed, Visibility::Revealed },
                                      { Visibility::Recognized, Visibility::Concealed },
                                      { Visibility::Revealed, Visibility::Revealed } }[visibility];
}

Visibility minesweeper::changeGuess(Visibility visibility)
{
  return map<Visibility, Visibility>{ { Visibility::Concealed, Visibility::Recognized },
                                      { Visibility::Recognized, Visibility::Concealed },
                                      { Visibility::Revealed, Visibility::Revealed } }[visibility];
}