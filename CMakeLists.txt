cmake_minimum_required (VERSION 3.0)

project (Minesweeper CXX)
set (CMAKE_CXX_STANDARD 14)

add_executable (
  ${PROJECT_NAME}
  board.cpp
  board.h
  input.cpp
  input.h
  main.cpp
  mines.cpp
  mines.h
  move.cpp
  move.h
  optional.h
  position.cpp
  position.h
  positions.cpp
  positions.h
  print.cpp
  print.h
  rectangle.cpp
  rectangle.h
  rectangles.cpp
  rectangles.h
  state.cpp
  state.h
  uncover.cpp
  uncover.h
  rules.txt
  todo.txt
  )
