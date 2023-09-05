cmake_minimum_required(VERSION 3.22.1)

project(GEA)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS off)

file(
  GLOB_RECURSE
  SOURCES
  CONFIGURE_DEPENDS
  "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

#sdl 
find_package(SDL2 REQUIRED)

add_executable(
  ${PROJECT_NAME}
  src/main.cpp
  ${SOURCES}
)

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC ${PROJECT_SOURCE_DIR}/src
  PUBLIC ${PROJECT_SOURCE_DIR}/src/Game
  PUBLIC ${PROJECT_SOURCE_DIR}/src/Pong
  PUBLIC ${PROJECT_SOURCE_DIR}/src/CustomObj
  PUBLIC ${PROJECT_SOURCE_DIR}/src/Scene
  PUBLIC ${PROJECT_SOURCE_DIR}/src/ECS
)

target_link_libraries(
  ${PROJECT_NAME}
  PRIVATE ${SDL2_LIBRARIES}
  SDL2_image
)
# PRIVATE GL SDL2main SDL2

