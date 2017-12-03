cmake_minimum_required(VERSION 3.6)
project(SDL-GOL)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(./lib)


file(GLOB_RECURSE SOURCE_FILES
        "src/*.cpp"
        "src/*.h"
)

add_executable(SDL-GOL ${SOURCE_FILES} src/visual/TextureWrapper.cpp src/visual/TextureWrapper.h src/visual/ButtonWidget.cpp src/visual/ButtonWidget.h src/world/WorldSaver.cpp src/world/WorldSaver.h)

target_link_libraries(SDL-GOL SDL2-static SDL2main)

include_directories(${SDL2_SOURCE_DIR}/include)

file(COPY textures/ DESTINATION textures/)