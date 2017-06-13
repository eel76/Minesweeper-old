cmake_minimum_required (VERSION 3.0)

project (Minesweeper CXX)
set (CMAKE_CXX_STANDARD 14)

add_executable (
  ${PROJECT_NAME}
  board.h
  cell.cpp
  cell.h
  cells.cpp
  cells.h
  columns.cpp
  columns.h
  filter.cpp
  filter.h
  game.cpp
  game.h
  group.cpp
  group.h
  input.cpp
  input.h
  main.cpp
  mine.cpp
  mine.h
  neighbors.cpp
  neighbors.h
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
  rows.cpp
  rows.h
  size.h
  uncover.cpp
  uncover.h
  Readme.md
  )
