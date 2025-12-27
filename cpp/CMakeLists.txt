cmake_minimum_required(VERSION 3.10)

project(aero_surrogate_model)

set(CMAKE_CXX_STANDARD 17)

add_executable(aero_surrogate
    main.cpp
    surrogate_model.cpp
)
