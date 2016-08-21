cmake_minimum_required(VERSION 3.3)
project(DV1490_lab2_99)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES TestDeepCopyingOfList.cpp   ICircularDoubleDirectedList.h CircularDoubleDirectedList.h  )
#Card.cpp Card.h Player.cpp Player.h TestDeepCopyingOfList.cpp   NinetyNine.cpp  TestFunctionalityOfList.cpp IStack.h Stack.h Dynamictest.cpp
add_executable(DV1490_lab2_99 ${SOURCE_FILES})