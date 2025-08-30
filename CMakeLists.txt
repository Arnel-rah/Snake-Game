cmake_minimum_required(VERSION 3.10)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(SFML_DIR "C:/SFML/SFML-2.6.2/lib/cmake/SFML")

find_package(SFML 2.6.2 COMPONENTS graphics window system REQUIRED)

add_executable(SnakeGame
    src/main.cpp
    src/game.cpp
    src/snake.cpp
    src/food.cpp
)

target_link_libraries(SnakeGame PRIVATE sfml-graphics sfml-window sfml-system)
