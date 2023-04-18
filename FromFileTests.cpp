//
// Created by Michal Lewandowski on 4/11/2023.
//

#include "FromFileTests.h"
#include "Time.h"
#include "DynamicArray.h"
#include "DoublyLinkedList.h"
#include "BinaryHeap.h"
#include "RedBlackTree.h"
#include "WriteToFile.h"
#include <iostream>
#include <fstream>
#include <random>

void FromFileTests::ArrayTest() {
    std::string fileWriteName = "../DynamicArray.txt";
    Time time;
    DynamicArray array;
    int choice = -1;
    int value;
    int numberOfIterations;
    std::string inputFileName;
    std::ifstream inputFile;

    std::cout << "Enter name of input file with data:  ";
    std::cin >> inputFileName;

    inputFile.open(inputFileName);

    if (inputFile.is_open()) {
        std::cout << "Input file opened." << inputFileName << "\n";
    } else {
        std::cout << "Failed to open input file.\n";
        return;
    }

    while (inputFile.good()) {
        inputFile >> value;
        array.insertHead(value);
    }

    std::cout << "Enter number of operations measure:\n";
    std::cin >> numberOfIterations;

    std::random_device rd; // non-deterministic generator
    std::uniform_int_distribution<> dist(1, 10000000); // distribute results between
    std::uniform_int_distribution<> dist2(1, array.size); // distribute results between
    std::mt19937 gen(rd()); // random engine seeded with rd()

    while (choice != 0) {
        std::cout << "Choose what do you want to do:\n";
        std::cout << "   1. Insert head\n";
        std::cout << "   2. Insert tail\n";
        std::cout << "   3. Insert anywhere\n";
        std::cout << "   4. Remove head\n";
        std::cout << "   5. Remove tail\n";
        std::cout << "   6. Remove any\n";
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
                WriteToFile::writeOperationToFileTXT(fileWriteName, "Insert head");
                for (int i =0; i < numberOfIterations; i++) {
                    time.timeStart();
                    array.insertHead(dist(gen));
                    time.timeStop();
                    std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                    WriteToFile::appendToFileTXT(fileWriteName, time.elapsedTime());
                }
                inputFile.close();
                break;

            case 2:
                WriteToFile::writeOperationToFileTXT(fileWriteName, "Insert tail");
                for (int i =0; i < numberOfIterations; i++) {
                    time.timeStart();
                    array.insertTail(dist(gen));
                    time.timeStop();
                    std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                    WriteToFile::appendToFileTXT(fileWriteName, time.elapsedTime());
                }
                inputFile.close();
                break;

            case 3:
                WriteToFile::writeOperationToFileTXT(fileWriteName, "Insert anywhere");
                for (int i =0; i < numberOfIterations; i++) {
                    time.timeStart();
                    array.insert(dist(gen), dist2(gen));
                    time.timeStop();
                    std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                    WriteToFile::appendToFileTXT(fileWriteName, time.elapsedTime());
                }
                inputFile.close();
                break;

            case 4:
                WriteToFile::writeOperationToFileTXT(fileWriteName, "Remove head");
                for (int i =0; i < numberOfIterations; i++) {
                    time.timeStart();
                    array.removeHead();
                    time.timeStop();
                    std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                    WriteToFile::appendToFileTXT(fileWriteName, time.elapsedTime());
                }
                inputFile.close();
                break;

            case 5:
                WriteToFile::writeOperationToFileTXT(fileWriteName, "Remove tail");
                for (int i =0; i < numberOfIterations; i++) {
                    time.timeStart();
                    array.removeTail();
                    time.timeStop();
                    std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                    WriteToFile::appendToFileTXT(fileWriteName, time.elapsedTime());
                }
                inputFile.close();
                break;

            case 6:
                WriteToFile::writeOperationToFileTXT(fileWriteName, "Remove any");
                for (int i =0; i < numberOfIterations; i++) {
                    time.timeStart();
                    array.remove(dist2(gen));
                    time.timeStop();
                    std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                    WriteToFile::appendToFileTXT(fileWriteName, time.elapsedTime());
                }
                inputFile.close();
                break;

            case 7:
                WriteToFile::writeOperationToFileTXT(fileWriteName, "Check if exists");
                for (int i =0; i < numberOfIterations; i++) {
                    time.timeStart();
                    array.isNumberInArray(dist(gen));
                    time.timeStop();
                    std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                    WriteToFile::appendToFileTXT(fileWriteName, time.elapsedTime());
                }

                inputFile.close();
                break;

            case 8:
                time.timeStart();
                array.displayArray();
                time.timeStop();
                std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                inputFile.close();
                break;
        }
    }
}

void FromFileTests::DoublyLinkedListTest() {
    std::string fileWriteName = "../DoublyLinkedList.txt";
    Time time;
    DoublyLinkedList list;
    int choice = -1;
    int value;
    int numberOfIterations;
    std::string inputFileName;
    std::ifstream inputFile;

    std::cout << "Enter name of input file with data:  ";
    std::cin >> inputFileName;

    inputFile.open(inputFileName);

    if (inputFile.is_open()) {
        std::cout << "Input file opened." << inputFileName << "\n";
    } else {
        std::cout << "Failed to open input file.\n";
        return;
    }

    while (inputFile.good()) {
        inputFile >> value;
        list.insertHead(value);
    }

    std::cout << "Enter number of operations measure:\n";
    std::cin >> numberOfIterations;

    std::random_device rd; // non-deterministic generator
    std::uniform_int_distribution<> dist(1, 10000000); // distribute results between
    std::uniform_int_distribution<> dist2(1, list.size); // distribute results between
    std::mt19937 gen(rd()); // random engine seeded with rd()

    while (choice != 0) {
        std::cout << "Choose what do you want to do:\n";
        std::cout << "   1. Insert head\n";
        std::cout << "   2. Insert tail\n";
        std::cout << "   3. Insert anywhere\n";
        std::cout << "   4. Remove head\n";
        std::cout << "   5. Remove tail\n";
        std::cout << "   6. Remove any\n";
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
                WriteToFile::writeOperationToFileTXT(fileWriteName, "Insert head");
                for (int i =0; i < numberOfIterations; i++) {
                    time.timeStart();
                    list.insertHead(dist(gen));
                    time.timeStop();
                    std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                    WriteToFile::appendToFileTXT(fileWriteName, time.elapsedTime());
                }
                inputFile.close();
                break;

            case 2:
                WriteToFile::writeOperationToFileTXT(fileWriteName, "Insert tail");
                for (int i =0; i < numberOfIterations; i++) {
                    time.timeStart();
                    list.insertTail(dist(gen));
                    time.timeStop();
                    std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                    WriteToFile::appendToFileTXT(fileWriteName, time.elapsedTime());
                }
                inputFile.close();
                break;

            case 3:
                WriteToFile::writeOperationToFileTXT(fileWriteName, "Insert at index");
                for (int i =0; i < numberOfIterations; i++) {
                    time.timeStart();
                    list.insert(dist(gen),dist2(gen) );
                    time.timeStop();
                    std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                    WriteToFile::appendToFileTXT(fileWriteName, time.elapsedTime());
                }
                inputFile.close();
                break;

            case 4:
                WriteToFile::writeOperationToFileTXT(fileWriteName, "Remove head");
                for (int i =0; i < numberOfIterations; i++) {
                    time.timeStart();
                    list.removeHead();
                    time.timeStop();
                    std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                    WriteToFile::appendToFileTXT(fileWriteName, time.elapsedTime());
                }
                inputFile.close();
                break;

            case 5:
                WriteToFile::writeOperationToFileTXT(fileWriteName, "Remove tail");
                for (int i =0; i < numberOfIterations; i++) {
                    time.timeStart();
                    list.removeTail();
                    time.timeStop();
                    std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                    WriteToFile::appendToFileTXT(fileWriteName, time.elapsedTime());
                }
                inputFile.close();
                break;

            case 6:
                WriteToFile::writeOperationToFileTXT(fileWriteName, "Remove any");
                for (int i =0; i < numberOfIterations; i++) {
                    time.timeStart();
                    list.remove(dist2(gen));
                    time.timeStop();
                    std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                    WriteToFile::appendToFileTXT(fileWriteName, time.elapsedTime());
                }
                inputFile.close();
                break;

            case 7:
                WriteToFile::writeOperationToFileTXT(fileWriteName, "Check if exists");
                for (int i =0; i < numberOfIterations; i++) {
                    time.timeStart();
                    list.isNumberInList(dist(gen));
                    time.timeStop();
                    std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                    WriteToFile::appendToFileTXT(fileWriteName, time.elapsedTime());
                }
                inputFile.close();
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

void FromFileTests::BinaryHeapTest() {
    std::string fileWriteName = "../BinaryHeap.txt";
    Time time;
    BinaryHeap binaryHeap;
    int choice = -1;
    int value;
    int numberOfIterations;
    std::string inputFileName;
    std::ifstream inputFile;

    std::cout << "Enter name of input file with data:  ";
    std::cin >> inputFileName;

    inputFile.open(inputFileName);

    if (inputFile.is_open()) {
        std::cout << "Input file opened." << inputFileName << "\n";
    } else {
        std::cout << "Failed to open input file.\n";
        return;
    }

    while (inputFile.good()) {
        inputFile >> value;
        binaryHeap.insert(value);
    }

    std::cout << "Enter number of operations measure:\n";
    std::cin >> numberOfIterations;

    std::random_device rd; // non-deterministic generator
    std::uniform_int_distribution<> dist(1, 10000000); // distribute results between
    std::mt19937 gen(rd()); // random engine seeded with rd()

    while (choice != 0) {
        std::cout << "Choose what do you want to do:\n";
        std::cout << "    1. Insert value\n";
        std::cout << "    2. Delete Root\n";
        std::cout << "    3. Check if value exists\n";
        std::cout << "    4. Print Heap\n";
        std::cout << "    0. Exit\n" << "\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        switch (choice) {
            default:
                std::cout << "Wrong choice!\n";
                break;

            case 0:
                break;

            case 1:
                WriteToFile::writeOperationToFileTXT(fileWriteName, "Insert value");
                for (int i =0; i < numberOfIterations; i++) {
                    time.timeStart();
                    binaryHeap.insert(dist(gen));
                    time.timeStop();
                    std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                    WriteToFile::appendToFileTXT(fileWriteName, time.elapsedTime());
                }

            case 2:
                WriteToFile::writeOperationToFileTXT(fileWriteName, "Delete Root");
                for (int i =0; i < numberOfIterations; i++) {
                    time.timeStart();
                    binaryHeap.deleteRoot();
                    time.timeStop();
                    std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                    WriteToFile::appendToFileTXT(fileWriteName, time.elapsedTime());
                }
                break;

            case 3:
                WriteToFile::writeOperationToFileTXT(fileWriteName, "Check if value exists");
                for (int i =0; i < numberOfIterations; i++) {
                    time.timeStart();
                    binaryHeap.checkIfExist(dist(gen));
                    time.timeStop();
                    std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                    WriteToFile::appendToFileTXT(fileWriteName, time.elapsedTime());
                }
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

void FromFileTests::RedBlackTreeTest() {
    std::string fileWriteName = "../RedBlackTree.txt";
    Time time;
    RedBlackTree rBTree;
    int choice = -1;
    int value;
    int numberOfIterations;
    std::string inputFileName;
    std::ifstream inputFile;

    std::cout << "Enter name of input file with data:  ";
    std::cin >> inputFileName;

    inputFile.open(inputFileName);

    if (inputFile.is_open()) {
        std::cout << "Input file opened." << inputFileName << "\n";
    } else {
        std::cout << "Failed to open input file.\n";
        return;
    }

    while (inputFile.good()) {
        inputFile >> value;
        rBTree.insert(value);
    }

    std::cout << "Enter number of operations measure:\n";
    std::cin >> numberOfIterations;

    std::random_device rd; // non-deterministic generator
    std::uniform_int_distribution<> dist(1, 10000000); // distribute results between
//    std::uniform_int_distribution<> dist2(0, rBTree.size);
    std::mt19937 gen(rd()); // random engine seeded with rd()

    while (choice != 0) {
        std::cout << "Choose what do you want to do:\n";
        std::cout << "    1. Insert value\n";
        std::cout << "    2. Delete value\n";
        std::cout << "    3. Check if value exists\n";
        std::cout << "    4. Print Red-Black Tree\n";
        std::cout << "    5. Print Red-Black Tree inorder\n";
        std::cout << "    6. Print Red-Black Tree preorder\n";
        std::cout << "    7. Print Red-Black Tree postorder\n";
        std::cout << "    0. Exit\n" << "\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        switch (choice) {
            default:
                std::cout << "Wrong choice!\n";
                break;

            case 0:
                break;

            case 1:
                WriteToFile::writeOperationToFileTXT(fileWriteName, "Insert value");
                for (int i =0; i < numberOfIterations; i++) {
                    time.timeStart();
                    rBTree.insert(dist(gen));
                    time.timeStop();
                    std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                    WriteToFile::appendToFileTXT(fileWriteName, time.elapsedTime());
                }
                break;

            case 2:
                WriteToFile::writeOperationToFileTXT(fileWriteName, "Delete value");
                for (int i =0; i < numberOfIterations; i++) {
                    time.timeStart();
                    rBTree.deleteNode(dist(gen));
                    time.timeStop();
                    std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                    WriteToFile::appendToFileTXT(fileWriteName, time.elapsedTime());
                }
                break;

            case 3:
                WriteToFile::writeOperationToFileTXT(fileWriteName, "Check if value exists");
                time.timeStart();
                for (int i =0; i < numberOfIterations; i++) {
                    time.timeStart();
                    rBTree.searchTree(dist(gen));
                    time.timeStop();
                    std::cout << "Execution time: " << time.elapsedTime() << "ns\n";
                    WriteToFile::appendToFileTXT(fileWriteName, time.elapsedTime());
                }
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