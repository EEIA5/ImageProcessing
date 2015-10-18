cmake_minimum_required(VERSION 2.8)
project(ImageProcessing)
find_package(OpenCV 3.0.0 REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp)
add_executable(ImageProcessing ${SOURCE_FILES})

target_link_libraries(ImageProcessing
${OpenCV_LIBS}
)