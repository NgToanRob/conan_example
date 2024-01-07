cmake_minimum_required(VERSION 3.28.1)
project(ImageProcessing)


find_package(OpenCV REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} opencv::opencv)

# conan_basic_setup()
# find_package(OpenCV REQUIRED)
# target_include_directories(${OpenCV_INCLUDE_DIRS})
# target_link_libraries(ImageProcessing ${OpenCV_LIBS})

# find_package(OpenCV)
# target_link_libraries(build opencv::opencv)

# add_subdirectory(src)