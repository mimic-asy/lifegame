cmake_minimum_required (VERSION 3.22)

add_compile_options(-Werror -Wall -g)
project(board)

enable_testing() 

include(FetchContent)
FetchContent_Declare(
googletest
# Specify the commit you depend on and update it regularly.
URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)
include(CTest)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_library(lifegame board.cpp)
target_link_libraries(lifegame Eigen3::Eigen)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(lifegame_test test.cpp)
target_link_libraries(lifegame_test lifegame GTest::gtest_main)
gtest_add_tests(TARGET lifegame_test)
