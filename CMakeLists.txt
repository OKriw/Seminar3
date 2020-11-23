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
        main.cpp)

target_link_libraries(TTimer ${SQLITE3_LIBRARIES})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lsqlite3")
