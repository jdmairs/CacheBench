cmake_minimum_required(VERSION 3.11)

project(CacheBench CXX)

find_package(Boost 1.68.0 REQUIRED system random)

add_executable(CacheBench main.cpp)

target_include_directories(CacheBench PRIVATE ${Boost_INCLUDE_DIR})
target_link_libraries(CacheBench PUBLIC  ${Boost_LIBRARIES} )