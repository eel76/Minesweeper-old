cmake_minimum_required (VERSION 3.0)

project (Minesweeper CXX)
set (CMAKE_CXX_STANDARD 14)

add_executable (
  ${PROJECT_NAME}
  action.h
  board.h
  cell.cpp
  cell.h
  cells.cpp
  cells.h
  column.cpp
  column.h
  columns.cpp
  columns.h
  dimensions.h
  filter.cpp
  filter.h
  game.cpp
  game.h
  group.cpp
  group.h
  input.cpp
  input.h
  join.cpp
  join.h
  main.cpp
  mine.cpp
  mine.h
  mines.cpp
  mines.h
  move.cpp
  move.h
  neighbors.cpp
  neighbors.h
  offset.cpp
  offset.h
  offsets.cpp
  offsets.h
  parse.cpp
  parse.h
  position.cpp
  position.h
  positions.cpp
  positions.h
  preparation.cpp
  preparation.h
  print.cpp
  print.h
  row.cpp
  row.h
  rows.cpp
  rows.h
  state.cpp
  state.h
  transform.cpp
  transform.h
  uncover.cpp
  uncover.h
  Readme.md
  )
