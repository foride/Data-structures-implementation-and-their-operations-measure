//
// Created by Michal Lewandowski on 3/26/2023.
//

#include <iostream>
#include "Tests.h"
#include "FromFileTests.h"

int main() {
    int choice = -1;
    std::string fromFile;

    while (choice != 0) {
        std::cout << "Select data structure:\n";
        std::cout << "1. Dynamic Array\n";
        std::cout << "2. Doubly Linked List\n";
        std::cout << "3. Binary Heap\n";
        std::cout << "4. Red-Black Tree\n";
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        std::cout << "Do you want to use data from File? Type yes/no: ";
        std::cin >> fromFile;
        switch (choice) {
            case 0:
                return 0;
            case 1:
                if (fromFile == "yes") {
                    FromFileTests::ArrayTest();
                } else
                    Tests::ArrayTest();
                break;
            case 2:
                if (fromFile == "yes") {
                    FromFileTests::DoublyLinkedListTest();
                } else
                    Tests::DoublyLinkedListTest();
                break;
            case 3:
                if (fromFile == "yes") {
                    FromFileTests::BinaryHeapTest();
                } else
                    Tests::BinaryHeapTest();
                break;
            case 4:
                if (fromFile == "yes") {
                    FromFileTests::RedBlackTreeTest();
                } else
                    Tests::RedBlackTreeTest();
                break;
            default:
                std::cout << "Wrong choice!\n";
                break;
        }
    }
    return 0;
}
