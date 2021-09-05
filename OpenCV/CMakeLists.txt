cmake_minimum_required(VERSION 3.0.0)
project(OpenCV VERSION 0.1.0)

set(OpenCV_DIR /usr/include/opencv4)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
include_directories(Images)
add_executable(DisplayImage DisplayImage.cpp)
add_executable(DisplayChannels ImageChannels.cpp)

target_link_libraries( DisplayImage ${OpenCV_LIBS} )
target_link_libraries( DisplayChannels ${OpenCV_LIBS} )
