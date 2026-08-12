cmake_minimum_required(VERSION 3.28)

project(BombRaiders
    VERSION 0.1
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

add_executable(BombRaiders
    src/main.cpp
    src/Level.cpp
    src/Player.cpp
)

target_include_directories(BombRaiders PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(BombRaiders PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)