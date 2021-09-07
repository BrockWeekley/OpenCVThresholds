cmake_minimum_required(VERSION "3.17")

project(assignment-one)

set(OpenCV_DIR ~/opencv/build)

set(CMAKE_CXX_STANDARD 14)

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(rgb2gray rgb2gray.cpp)
add_executable(gray2binary gray2binary.cpp)

target_link_libraries(rgb2gray ${OpenCV_LIBS} )
target_link_libraries(gray2binary ${OpenCV_LIBS} )
