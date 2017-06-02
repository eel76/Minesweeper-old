cmake_minimum_required (VERSION 3.0)

project (Minesweeper CXX)
set (CMAKE_CXX_STANDARD 14)

add_executable (
  ${PROJECT_NAME}
  board.cpp
  board.h
  column.cpp
  column.h
  game.cpp
  game.h
  input.cpp
  input.h
  main.cpp
  mine.cpp
  mine.h
  mines.cpp
  mines.h
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
  rectangle.cpp
  rectangle.h
  rectangles.cpp
  rectangles.h
  round.cpp
  round.h
  row.cpp
  row.h
  size.h
  state.cpp
  state.h
  uncover.cpp
  uncover.h
  Readme.md
  )
