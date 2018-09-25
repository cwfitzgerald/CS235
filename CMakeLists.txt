cmake_minimum_required(VERSION 3.12)
project(CS235 CXX)

include(dependencies/cmake-utils/include/clang_format.cmake)
include(dependencies/cmake-utils/include/linter.cmake)
include(dependencies/cmake-utils/include/warnings.cmake)

add_warnings()

add_linted_subdirectory(project1)
add_linted_subdirectory(project2)

configure_linter()