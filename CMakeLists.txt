cmake_minimum_required(VERSION 3.24)
project(Battleship)

set(CMAKE_CXX_STANDARD 11)

add_executable(Battleship source/main.cpp include/nave.h lib/nave.cpp include/corazzata.h include/supporto.h include/sottomarino.h lib/corazzata.cpp lib/supporto.cpp lib/sottomarino.cpp utilities/coordinata.cpp include/coordinata.h include/griglia.h utilities/griglia.cpp)
