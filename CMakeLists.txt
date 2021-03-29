cmake_minimum_required(VERSION 3.16.3)
project(swifft LANGUAGES C CXX VERSION 1.0.0)

add_compile_options(
  "-mavx2"
  "-fPIC"
  "-Wall" "-Wpedantic" "-Wextra" "-fexceptions"
  "$<$<CONFIG:RELEASE>:-Ofast>"
  "$<$<CONFIG:DEBUG>:-O0;-g3;-ggdb;--coverage>"
)
add_link_options(
  "$<$<CONFIG:DEBUG>:--coverage>"
)

add_executable(tester tester.c)
