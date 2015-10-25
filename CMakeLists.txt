cmake_minimum_required(VERSION 2.8)
project(ImageProcessing)
find_package(OpenCV REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES 
	src/main.cpp
	src/CubeDetector.cpp
	include/CubeDetector.h)

include_directories("${CMAKE_SOURCE_DIR}/include"
add_executable(ImageProcessing ${SOURCE_FILES})

target_link_libraries(ImageProcessing
${OpenCV_LIBS}
)
