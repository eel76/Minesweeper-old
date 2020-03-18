cmake_minimum_required (VERSION 3.0)

project (Minesweeper CXX)
set (CMAKE_CXX_STANDARD 17)

add_executable (
  ${PROJECT_NAME}
  include/ask.h
  src/board.cpp
  include/board.h
  src/cell.cpp
  include/cell.h
  src/cells.cpp
  include/cells.h
  src/column.cpp
  include/column.h
  src/columns.cpp
  include/columns.h
  src/combos.cpp
  include/combos.h
  src/player/choose.cpp
  src/player/computer.cpp
  include/player/choose.h
  include/player/computer.h
  include/concealed.h
  include/deadly.h
  src/filter.cpp
  include/filter.h
  src/getline.cpp
  include/getline.h
  src/group.cpp
  include/group.h
  include/hazard.h
  src/player/human.cpp
  include/player/human.h
  src/main.cpp
  include/marked.h
  src/mined.cpp
  include/mined.h
  src/move.cpp
  include/move.h
  include/negligible.h
  include/neighbor.h
  include/only.h
  src/parse.cpp
  include/parse.h
  src/play.cpp
  include/play.h
  include/player.h
  src/position.cpp
  include/position.h
  include/positions.h
  src/preparation.cpp
  include/preparation.h
  src/print.cpp
  include/print.h
  src/reveal.cpp
  include/reveal.h
  include/revealed.h
  src/row.cpp
  include/row.h
  src/rows.cpp
  include/rows.h
  src/severity.cpp
  include/severity.h
  src/state.cpp
  include/state.h
  include/take.h
  src/threat.cpp
  include/threat.h
  src/to_string.cpp
  include/to_string.h
  Readme.md
  )

target_include_directories (
  ${PROJECT_NAME}
  PRIVATE include
  )
