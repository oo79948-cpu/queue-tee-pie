cmake_minimum_required(VERSION 3.24)

project(queue_tee_pie)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.8.1
)

FetchContent_MakeAvailable(Catch2)

add_executable(cutie_test tests/cutie_test.cpp src/cutie.cpp
        src/cutie.hpp)
add_executable(main main.cpp src/cutie.cpp)

target_link_libraries(cutie_test PRIVATE Catch2::Catch2WithMain)
