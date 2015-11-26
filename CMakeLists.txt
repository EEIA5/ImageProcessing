cmake_minimum_required(VERSION 2.8)
project(ImageProcessing)
find_package(OpenCV REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES 
	src/main.cpp
	src/CubeDetector.cpp
	include/CubeDetector.h
	src/Cube.cpp 
	src/Cube.h 
	src/Wall.cpp 
	src/Wall.h 
	src/Cell.cpp 
	src/Cell.h
	src/CubesAlgorithm.h
	src/CubesAlgorithm.cpp
	src/CubeAlgorithmClass.cpp
	src/CubeAlgorithmClass.h
	src/CubeDetector.h)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(ImageProcessing ${SOURCE_FILES})

target_link_libraries(ImageProcessing
${OpenCV_LIBS}
)
