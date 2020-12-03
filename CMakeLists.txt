cmake_minimum_required(VERSION 3.12)
project(Seminar3)

set(CMAKE_CXX_STANDARD 14)
add_executable(TTimer
        Timer.h
        Timer.cpp
        Task.h
        Task.cpp
        Mgr.h
        Mgr.cpp
        Client.h
        Client.cpp
        Storage.h
        Storage.cpp
        StorageSql.cpp
        main.cpp
        sqlite3.c
        sqlite3.h)


