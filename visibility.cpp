#include "visibility.h"
#include <map>

using namespace minesweeper;
using namespace std;

using Action = map<Visibility, Visibility>;

Visibility operator|(Visibility visibility, Action action)
{
  return action[visibility];
}

Action reveal()
{
  return { { Concealed, Revealed }, { Recognized, Concealed }, { Revealed, Revealed } };
}

Action changeGuess()
{
  return { { Concealed, Recognized }, { Recognized, Concealed }, { Revealed, Revealed } };
}

Visibility minesweeper::reveal(Visibility visibility)
{
  return visibility | ::reveal();
}

Visibility minesweeper::changeGuess(Visibility visibility)
{
  return visibility | ::changeGuess();
}