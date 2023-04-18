cmake_minimum_required(VERSION 3.24)
project(SDiZO)

set(CMAKE_CXX_STANDARD 17)

add_executable(SDiZO main.cpp DynamicArray.cpp DynamicArray.h DoublyLinkedList.cpp DoublyLinkedList.h Node.cpp Node.h BinaryHeap.cpp BinaryHeap.h RedBlackTree.cpp RedBlackTree.h Tests.cpp Tests.h Time.cpp Time.h FromFileTests.cpp FromFileTests.h WriteToFile.cpp WriteToFile.h)
