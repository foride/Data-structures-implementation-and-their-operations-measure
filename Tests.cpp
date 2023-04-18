//
// Created by Michal Lewandowski on 4/8/2023.
//
#include <iostream>
#include "Tests.h"
#include "DynamicArray.h"
#include "DoublyLinkedList.h"
#include "Time.h"
#include "BinaryHeap.h"
#include "RedBlackTree.h"
#include <random>
#include <unordered_set>

void Tests::ArrayTest() {
    Time time;
    DynamicArray array;
    int choice = -1;
    int value;
    int index;
    int structureSize;
    std::cout << "Initialization of dynamic array, enter a quantity of elements:\n";
    std::cin >> structureSize;
    std::unordered_set<int> set;

    std::random_device rd; // non-deterministic generator
    std::uniform_int_distribution<> dist(1, 10000000); // distribute results between
    std::mt19937 gen(rd()); // random engine seeded with rd()

    for (int i = 0; i < structureSize; i++)
    {
        set.insert(dist(gen));  // pass the generator to the distribution
    }

    auto itr = set.begin();
    while(itr != set.end()){

        array.insertHead(*itr);
        itr++;

    }
    std::cout << "Dynamic array initialized with " << set.size() << " elements\n";

    while (choice != 0) {
        std::cout << "Choose what do you want to do:\n";
        std::cout << "   1. Insert head\n";
        std::cout << "   2. Insert tail\n";
        std::cout << "   3. Insert anywhere\n";
        std::cout << "   4. Remove head\n";
        std::cout << "   5. Remove tail\n";
        std::cout << "   6. Remove specific value\n";
        std::cout << "   7. Check if exists\n";
        std::cout << "   8. Display dynamic Array\n";
        std::cout << "   0. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        switch (choice) {
            default:
                std::cout << "Wrong choice!\n";
                break;

            case 0:
                break;

            case 1:
                std::cout << "Enter value: ";
                std::cin >> value;
                time.timeStart();
                array.insertHead(value);
                time.timeStop();
                std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                break;

            case 2:
                std::cout << "Enter value: ";
                std::cin >> value;
                time.timeStart();
                array.insertTail(value);
                time.timeStop();
                std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                break;

            case 3:
                std::cout << "Enter value: ";
                std::cin >> value;
                std::cout << "Enter index: ";
                std::cin >> index;
                time.timeStart();
                array.insert(value, index);
                time.timeStop();
                std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                break;

            case 4:
                time.timeStart();
                array.removeHead();
                time.timeStop();
                std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                break;

            case 5:
                time.timeStart();
                array.removeTail();
                time.timeStop();
                std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                break;

            case 6:
                std::cout << "Enter index: ";
                std::cin >> index;
                time.timeStart();
                array.remove(index);
                time.timeStop();
                std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                break;

            case 7:
                std::cout << "Enter value: ";
                std::cin >> value;
                time.timeStart();
                array.isNumberInArray(value);
                time.timeStop();
                std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                break;

            case 8:
                time.timeStart();
                array.displayArray();
                time.timeStop();
                std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                break;
        }

    }
}

void Tests::DoublyLinkedListTest() {
    Time time;
    DoublyLinkedList list;
    int choice = -1;
    int value;
    int index;
    int structureSize;
    std::cout << "Initialization of Doubly Linked List, enter a quantity of elements:\n";
    std::cin >> structureSize;
    std::unordered_set<int> set;

    std::random_device rd; // non-deterministic generator
    std::uniform_int_distribution<> dist(1, 10000000); // distribute results between
    std::mt19937 gen(rd()); // random engine seeded with rd()

    for (int i = 0; i < structureSize; i++)
    {
        set.insert(dist(gen));  // pass the generator to the distribution
    }

    auto itr = set.begin();
    while(itr != set.end()){

        list.insertHead(*itr);
        itr++;

    }
    std::cout << "Doubly Linked List initialized with " << set.size() << " elements\n";


    while (choice != 0) {
        std::cout << "Choose what do you want to do:\n";
        std::cout << "   1. Insert head\n";
        std::cout << "   2. Insert tail\n";
        std::cout << "   3. Insert anywhere\n";
        std::cout << "   4. Remove head\n";
        std::cout << "   5. Remove tail\n";
        std::cout << "   6. Remove specific value\n";
        std::cout << "   7. Check if exists\n";
        std::cout << "   8. Display Doubly Linked List\n";
        std::cout << "   9. Display Doubly Linked List backwards\n";
        std::cout << "   0. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice) {
            default:
                std::cout << "Wrong choice!\n";
                break;

            case 0:
                break;

            case 1:
                std::cout << "Enter value: ";
                std::cin >> value;
                time.timeStart();
                list.insertHead(value);
                time.timeStop();
                std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                break;

            case 2:
                std::cout << "Enter value: ";
                std::cin >> value;
                time.timeStart();
                list.insertTail(value);
                time.timeStop();
                std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                break;

            case 3:
                std::cout << "Enter value: ";
                std::cin >> value;
                std::cout << "Enter index: ";
                std::cin >> index;
                time.timeStart();
                list.insert(value, index);
                time.timeStop();
                std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                break;

            case 4:
                time.timeStart();
                list.removeHead();
                time.timeStop();
                std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                break;

            case 5:
                time.timeStart();
                list.removeTail();
                time.timeStop();
                std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                break;

            case 6:
                std::cout << "Enter index: ";
                std::cin >> index;
                time.timeStart();
                list.remove(index);
                time.timeStop();
                std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                break;

            case 7:
                std::cout << "Enter value: ";
                std::cin >> value;
                time.timeStart();
                list.isNumberInList(value);
                time.timeStop();
                std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                break;

            case 8:
                time.timeStart();
                list.displayList();
                time.timeStop();
                std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                break;
            case 9:
                time.timeStart();
                list.displayListBackward();
                time.timeStop();
                std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                break;
        }

    }
}

void Tests::BinaryHeapTest() {
    Time time;
    BinaryHeap binaryHeap;
    int choice = -1;
    int value;
    bool ifExist;
    int structureSize;
    std::cout << "Initialization of Binary Heap, enter a quantity of elements:\n";
    std::cin >> structureSize;
    std::unordered_set<int> set;

    std::random_device rd; // non-deterministic generator
    std::uniform_int_distribution<> dist(1, 10000000); // distribute results between
    std::mt19937 gen(rd()); // random engine seeded with rd()

    for (int i = 0; i < structureSize; i++)
    {
        set.insert(dist(gen));  // pass the generator to the distribution
    }

    auto itr = set.begin();
    while(itr != set.end()){

        binaryHeap.insert(*itr);
        itr++;

    }
    std::cout << "Binary Heap initialized with " << set.size() << " elements\n";

    while (choice != 0) {
        std::cout << "Choose what do you want to do:\n";
        std::cout << "    1. Insert value\n";
        std::cout << "    2. Delete Root\n";
        std::cout << "    3. Check if value exists\n";
        std::cout << "    4. Print Binary Heap\n";
        std::cout << "    0. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        switch (choice) {
            default:
                std::cout << "Wrong choice!\n";
                break;

            case 0:
                break;

            case 1:
                std::cout << "Enter value: ";
                std::cin >> value;
                time.timeStart();
                binaryHeap.insert(value);
                time.timeStop();
                std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                break;

            case 2:
                time.timeStart();
                binaryHeap.deleteRoot();
                time.timeStop();
                std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                break;

            case 3:
                std::cout << "Enter value: ";
                std::cin >> value;
                time.timeStart();
                ifExist = binaryHeap.checkIfExist(value);
                if (ifExist) {
                    std::cout << "This element exists in Heap \n";
                } else
                    std::cout << "This element doesn't exists in Heap \n";
                time.timeStop();
                std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                break;

            case 4:
                time.timeStart();
                binaryHeap.displayHeap();
                time.timeStop();
                std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                break;
        }

    }
}

void Tests::RedBlackTreeTest() {
    Time time;
    RedBlackTree rBTree;
    int choice = -1;
    int value;
    int structureSize;
    std::cout << "Initialization of Red-Black Tree, enter a quantity of elements:\n";
    std::cin >> structureSize;
    std::unordered_set<int> set;

    std::random_device rd; // non-deterministic generator
    std::uniform_int_distribution<> dist(1, 10000000); // distribute results between
    std::mt19937 gen(rd()); // random engine seeded with rd()

    for (int i = 0; i < structureSize; i++)
    {
        set.insert(dist(gen));  // pass the generator to the distribution
    }

    auto itr = set.begin();
    while(itr != set.end()){

        rBTree.insert(*itr);
        itr++;

    }
    std::cout << "Red-Black Tree initialized with " << set.size() << " elements\n";

    while (choice != 0) {
        std::cout << "Choose what do you want to do:\n";
        std::cout << "    1. Insert value\n";
        std::cout << "    2. Delete value\n";
        std::cout << "    3. Check if value exists\n";
        std::cout << "    4. Print Red-Black Tree\n";
        std::cout << "    5. Print Red-Black Tree inorder\n";
        std::cout << "    6. Print Red-Black Tree preorder\n";
        std::cout << "    7. Print Red-Black Tree postorder\n";
        std::cout << "    0. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        switch (choice) {
            default:
                std::cout << "Wrong choice!\n";
                break;

            case 0:
                break;

            case 1:
                std::cout << "Enter value: ";
                std::cin >> value;
                time.timeStart();
                rBTree.insert(value);
                time.timeStop();
                std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                break;

            case 2:
                std::cout << "Enter value: ";
                std::cin >> value;
                time.timeStart();
                rBTree.deleteNode(value);
                time.timeStop();
                std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                break;

            case 3:
                std::cout << "Enter value: ";
                std::cin >> value;
                time.timeStart();
                rBTree.searchTree(value);
                time.timeStop();
                std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                break;

            case 4:
                time.timeStart();
                rBTree.displayRBT();
                time.timeStop();
                std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                break;
            case 5:
                time.timeStart();
                rBTree.inorder();
                time.timeStop();
                std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                break;
            case 6:
                time.timeStart();
                rBTree.preorder();
                time.timeStop();
                std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                break;
            case 7:
                time.timeStart();
                rBTree.postorder();
                time.timeStop();
                std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                break;
        }
    }
}
