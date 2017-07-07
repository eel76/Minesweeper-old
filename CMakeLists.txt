cmake_minimum_required (VERSION 3.0)

project (Minesweeper CXX)
set (CMAKE_CXX_STANDARD 14)

add_executable (
  ${PROJECT_NAME}
  action.cpp
  action.h
  ask.cpp
  ask.h
  board.h
  cell.h
  cells.cpp
  cells.h
  column.cpp
  column.h
  columns.cpp
  columns.h
  combos.cpp
  combos.h
  computer.cpp
  computer.h
  dimensions.h
  game.cpp
  game.h
  group.cpp
  group.h
  hazard.h
  join.cpp
  join.h
  main.cpp
  mine.cpp
  mine.h
  move.cpp
  move.h
  parse.cpp
  parse.h
  player.cpp
  player.h
  position.cpp
  position.h
  positions.cpp
  positions.h
  preparation.cpp
  preparation.h
  print.cpp
  print.h
  reveal.cpp
  reveal.h
  row.cpp
  row.h
  rows.cpp
  rows.h
  severity.cpp
  severity.h
  test.cpp
  test.h
  threat.cpp
  threat.h
  transform.cpp
  transform.h
  visibility.cpp
  visibility.h
  Readme.md
  )
