cmake_minimum_required(VERSION 3.11...3.22)


project(mpc_example_app VERSION 1.0.1)

add_executable(mpc_example_app mpc_example.cpp)

find_package(MPCCasadiLib REQUIRED)

target_link_libraries(mpc_example_app mpc_casadi_lib)