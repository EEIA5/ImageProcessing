cmake_minimum_required(VERSION 2.8)
project(ImageProcessing)
find_package(OpenCV REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES 
	src/main.cpp
	src/CubeDetector.cpp
	include/CubeDetector.h
	src/Cube.cpp 
	include/Cube.h 
	src/Wall.cpp 
	include/Wall.h
	src/CubeAnalyzer.cpp
	include/CubeAnalyzer.h
	include/Colors.h
	include/ColorsRange.h
	include/Constants.h)

include_directories("${CMAKE_SOURCE_DIR}/include")

add_executable(ImageProcessing ${SOURCE_FILES})

target_link_libraries(ImageProcessing
${OpenCV_LIBS}
)