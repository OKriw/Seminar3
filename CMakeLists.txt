cmake_minimum_required(VERSION 3.17)
project(Seminar3)

set(CMAKE_CXX_STANDARD 11)

add_executable(Seminar3
                Task.h Task.cpp
                Timer.cpp Timer.h
                Client.h Client.cpp
                Mgr.cpp Mgr.h
                main.cpp)