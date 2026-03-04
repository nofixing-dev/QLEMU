cmake_minimum_required(VERSION 3.13)

project(QLEMU)

set(CMAKE_CXX_STANDARD 17)

add_executable(QLEMU
    src/main.cpp
    src/QuantumGate.cpp
    src/QuantumRegister.cpp
)
