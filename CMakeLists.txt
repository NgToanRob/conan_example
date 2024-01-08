cmake_minimum_required(VERSION 3.14)
project(ImageProcessing VERSION 0.1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Set include directories
include_directories(include)

# Add source files
file(GLOB SOURCES "src/*.cpp")

# OpenCV package
find_package(OpenCV REQUIRED)

# Create executable
add_executable(ImageProcessing ${SOURCES})
target_link_libraries(ImageProcessing ${OpenCV_LIBS})