cmake_minimum_required(VERSION 3.12)
project(draw_pl)

# Source files
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(SRC_FILES
    ${SRC_DIR}/canvas/canvas.c
    ${SRC_DIR}/canvas/pixel.c
    ${SRC_DIR}/shape/point.c
    ${SRC_DIR}/shape/point_style.c
    ${SRC_DIR}/shape/line.c
    ${SRC_DIR}/shape/line_style.c
    ${SRC_DIR}/shape/rectangle.c
    ${SRC_DIR}/shape/ellipse.c
)

set(TEST_DIR "${CMAKE_SOURCE_DIR}/tests")

# Include directories
include_directories(${SRC_DIR} ${TEST_DIR})

# Add executable
add_executable(draw_pl ${SRC_FILES} ${SRC_DIR}/main/main.c)

# Link libraries
find_package(PNG REQUIRED)
find_package(Freetype REQUIRED)
target_link_libraries(draw_pl 
  PNG::PNG
  Freetype::Freetype
  m
)

# Set compiler flags for draw_pl target
target_compile_options(draw_pl PRIVATE -Wall -Wextra -g)

set(TEST_DIR "${CMAKE_SOURCE_DIR}/tests")
set(TEST_FILES
    ${TEST_DIR}/shape/point_test.c
    ${TEST_DIR}/shape/line_test.c
    ${TEST_DIR}/shape/rectangle_test.c
    ${TEST_DIR}/shape/ellipse_test.c
)

# Add tests executable
add_executable(tests ${SRC_FILES} ${TEST_FILES} ${TEST_DIR}/main/main.c)

# Set compiler flags for tests target
target_compile_options(tests PRIVATE -Wall -Wextra -g)

# Link libraries for tests
target_link_libraries(tests PRIVATE
  PNG::PNG
  Freetype::Freetype
  m
  )
