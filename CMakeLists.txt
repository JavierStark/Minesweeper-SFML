cmake_minimum_required(VERSION 3.25)
project(MineSweeper)

set(CMAKE_CXX_STANDARD 17)
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.5 COMPONENTS system window graphics)

add_executable(MineSweeper main.cpp Field.cpp Field.h Cell.cpp Cell.h UI.cpp UI.h Counter.cpp Counter.h Button.cpp Button.h Timer.cpp Timer.h)
target_link_libraries(MineSweeper sfml-system sfml-window sfml-graphics -static)