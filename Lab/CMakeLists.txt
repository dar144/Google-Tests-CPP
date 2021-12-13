cmake_minimum_required(VERSION 3.10.2) 

project(my_cpp_project) 

add_subdirectory(googletest) 

include_directories(googletest/include) 

set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall")

set(INCLUDES ${PROJECT_SOURCE_DIR}/include)

include_directories(${INCLUDES})

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")
# file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/test/*.cpp")

add_executable(mytests test/mytests.cpp ${SOURCES}) 

target_link_libraries(mytests PRIVATE gtest) 

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})