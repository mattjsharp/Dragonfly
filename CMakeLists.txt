cmake_minimum_required(VERSION 3.14)
project(Dragonfly)

set(CMAKE_CXX_STANDARD 17)

# Add SFML 3.x
find_package(SFML 3 REQUIRED COMPONENTS system window graphics)

# Engine library
file(GLOB DF_SOURCES src/*.cpp)

add_library(dragonfly STATIC ${DF_SOURCES})
target_include_directories(dragonfly PUBLIC include)

# Link SFML targets
target_link_libraries(dragonfly
SFML::System
SFML::Window
SFML::Graphics
)

enable_testing()
add_subdirectory(tests/unit)
add_subdirectory(tests/integration)
