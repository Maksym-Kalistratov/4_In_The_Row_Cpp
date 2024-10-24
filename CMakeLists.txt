cmake_minimum_required(VERSION 3.27)
project(UTP_Project1_Lib)

set(CMAKE_CXX_STANDARD 17)

add_library(UTP_Project1_Lib SHARED library.cpp
        Engine_Engine.cpp
        GameProcessing.cpp
        GameProcessing.h)

target_include_directories(UTP_Project1_Lib PRIVATE "/Users/macbookpro/Library/Java/JavaVirtualMachines/openjdk-21/Contents/Home/include")

target_include_directories(UTP_Project1_Lib PRIVATE "/Users/macbookpro/Library/Java/JavaVirtualMachines/openjdk-21/Contents/Home/include/darwin")
