//
// Created by Michal Lewandowski on 3/28/2023.
//

#ifndef SDIZO_BINARYHEAP_H
#define SDIZO_BINARYHEAP_H


#include <cstdint>

class BinaryHeap {
public:
    int *array;
    int size;

    BinaryHeap();

    ~BinaryHeap();

    void insert(int32_t value);

    void deleteRoot();

    bool checkIfExist(int32_t value) const;

    void displayHeap();

private:
    void heapify() const;

    void printHeap(int *heapArray, int heapSize, int currentNodeIndex, int levelIndent);
};


#endif //SDIZO_BINARYHEAP_H
