cmake_minimum_required(VERSION 3.3)
project(DV1490_lab2_99)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES  Player.h Player.cpp Card.cpp Card.h  NinetyNine.cpp ICircularDoubleDirectedList.h CircularDoubleDirectedList.h IStack.h Stack.h )
#Card.cpp Card.h Player.cpp TestDeepCopyingOfList.cpp Player.h TestFunctionalityOfList.cpp    NinetyNine.cpp  TestFunctionalityOfList.cpp IStack.h Stack.h Dynamictest.cpp
add_executable(DV1490_lab2_99 ${SOURCE_FILES})