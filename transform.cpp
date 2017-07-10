#include "transform.h"

// std::string minesweeper::toString(Threat threat)
//{
//  return Stringify<Visibility>{ { Visibility::Concealed, [] { return "#"s; }
//  }, { Visibility::Recognized, [] { return "*"s; } }, { Visibility::Revealed,
//  [=] {
//    return Stringify<Severity>{
//      { Severity::Negligible, [] { return "0"s; } },
//      { Severity::Deadly, [] { return "X"s; } }
//    }[get<Severity>(threat)]();
//  } } }[get<Visibility>(threat)]();
//}

std::vector<std::string> minesweeper::toString(Cells cells)
{
  auto strings = std::vector<std::string>{ cells.size() };

  for (auto cell : cells)
    strings.push_back(to_string(get<Threat>(cell)));

  return strings;
}