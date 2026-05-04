cmake_minimum_required(VERSION 4.2)
project(Learning)

set(CMAKE_CXX_STANDARD 20)

add_executable(Learning
        main.cpp
        Item.h
        Inventory.cpp
        Inventory.h
        Logger.h
        cmake-build-debug/TextInputApi.h
        DynamicArray.h
        SinglyLinkedList.h
        Deque.h)
