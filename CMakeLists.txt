cmake_minimum_required(VERSION 2.8)
project(ImageProcessing)
find_package(OpenCV REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/RubiksCubeSolveAlgorithm.cpp src/Cube.cpp src/Cube.h src/Wall.cpp src/Wall.h src/Cell.cpp src/Cell.h)

add_executable(ImageProcessing ${SOURCE_FILES})

target_link_libraries(ImageProcessing
${OpenCV_LIBS}
)
