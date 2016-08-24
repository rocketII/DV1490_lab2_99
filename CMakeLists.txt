cmake_minimum_required(VERSION 3.3)
project(DV1490_lab2_99)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES ICircularDoubleDirectedList.h CircularDoubleDirectedList.h Card.cpp Card.h Player.cpp Player.h IStack.h Stack.h  NinetyNine.cpp )
# ICircularDoubleDirectedList.h CircularDoubleDirectedList.h Card.cpp Card.h Player.cpp Player.h TestDeepCopyingOfList.cpp  TestFunctionalityOfList.cpp    NinetyNine.cpp  TestFunctionalityOfList.cpp IStack.h Stack.h Dynamictest.cpp
#set(SOURCE_FILES Card.cpp Card.h IStack.h Stack.h  Dynamictest.cpp )

add_executable(DV1490_lab2_99 ${SOURCE_FILES})