cmake_minimum_required(VERSION 3.11)

project(CacheBench CXX)

add_executable(CacheBench main.cpp)

find_package(Boost 1.68.0 REQUIRED system random)

 find_package(benchmark CONFIG REQUIRED)
 target_link_libraries(CacheBench PRIVATE benchmark::benchmark benchmark::benchmark_main)

enable_testing()
find_package(GTest REQUIRED)
target_link_libraries(CacheBench PRIVATE GTest::GTest GTest::Main)
add_test(AllTestsInMain CacheBench)




target_include_directories(CacheBench PUBLIC ${Boost_INCLUDE_DIR})
target_link_libraries(CacheBench PUBLIC  ${Boost_LIBRARIES} )