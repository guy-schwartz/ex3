cmake_minimum_required(VERSION 3.22)
project(ex3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex3
        HealthPoints.cpp
        HealthPoints.h
        HealthPointsExampleTest.cpp
        Queue.cpp
        Queue.h
        QueueExampleTests.cpp
        TestMain.cpp
        TestUtils.h)
