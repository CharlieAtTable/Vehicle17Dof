cmake_minimum_required(VERSION 3.0)

# other names for sub dirs
set(curr_dir ${CMAKE_CURRENT_SOURCE_DIR})
set(steering_dir ${curr_dir}/steering_system)
set(tire_dir ${curr_dir}/tires)
set(sprung_dir ${curr_dir}/sprung)
set(suspension_dir ${curr_dir}/suspension)
set(wheel_dir ${curr_dir}/wheels)

# project name
project(seventeenDof) 

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20") # using C++20

# Add header file include directories
include_directories(
    ./include
    ${steering_dir}/include
    ${tire_dir}/include
    ${sprung_dir}/include
    ${suspension_dir}/include
    ${wheel_dir}/include
)

# Add block directories
add_subdirectory(steering_system)
add_subdirectory(tires)
add_subdirectory(sprung)
add_subdirectory(suspension)
add_subdirectory(wheels)

# Target
add_executable(seventeenDof main.cpp)
target_link_libraries(seventeenDof tires steering_system sprung suspension wheels)
