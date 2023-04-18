//
// Created by Michal Lewandowski on 3/28/2023.
//

#include "BinaryHeap.h"
#include <iostream>
// no-argument constructor initializing array variable pointer to null and size to zero
BinaryHeap::BinaryHeap() {
    BinaryHeap::array = nullptr;
    BinaryHeap::size = 0;
}
// destructor, deletes the array
BinaryHeap::~BinaryHeap() {
    delete []array;
}
// inserts specified value to heap
void BinaryHeap::insert(int32_t value) {

    if (size == 0) {
        // checks if array size is equal to 0
        array = new int32_t[1]; // creates new dynamic array and sets its size as 1
        array[0] = value; // sets value of the first index as the inserted value
        size++;
        return;

    } else {
        // creates a new array with size increased by one
        int32_t *newArray = new int32_t[size + 1];
        for (int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }
        newArray[size] = value;
        delete []array; // free the memory allocated for the current array
        array = newArray;
        size++;
        BinaryHeap::heapify();

    }
}
// deletes heap's root
void BinaryHeap::deleteRoot() {

    if (size != 0) {

        int32_t *newArray = new int32_t[size - 1];
        for (int i = 1; i < size; i++) {
            newArray[i - 1] = array[i];
        }
        delete []array;
        array = newArray;
        size--;
        BinaryHeap::heapify();
    }
}
// checks if an element with the given value exists in the heap
bool BinaryHeap::checkIfExist(int32_t value) const {

    if (array == nullptr) {
        std::cout << "BinaryHeap is empty!\n";
    } else {
        for (int i = 0; i < size; i++) {
            if (value == array[i]) {
                std::cout << "Number exists in the BinaryHeap on index " << i << "\n";
                return true;
            }
        }
    }
    return false;
}
// rearranges a heap in order to maintain its property
void BinaryHeap::heapify() const {
    int32_t parent, leftChild, rightChild, maxChild;
    // iterates from the end of the heap to its beginning
    for (int i = size; i >= 0; i--) {
        parent = i;
        // performs heap rearrange operations for each node
        while (true) {
            leftChild = 2 * parent + 1;
            rightChild = 2 * parent + 2;
            // checks whether the heap has left child
            if (leftChild >= size) {
                break;
            }
            // checks whether the heap has right child and value of the right child is higher than the left child
            if (rightChild < size && array[rightChild] > array[leftChild]) {
                maxChild = rightChild;
            } else {
                maxChild = leftChild;
            }
            // checks if the value of the parent is greater than the value of the largest child
            if (array[parent] >= array[maxChild]) {
                break;
            }
            // swaps parent and largest child values and update parent value
            int temp = array[parent];
            array[parent] = array[maxChild];
            array[maxChild] = temp;
            parent = maxChild;
        }
    }
}
// console display of the heap
void BinaryHeap::displayHeap() {
    // if the heap is not empty, calls the printHeap function to print the heap
    if (array != nullptr) {
        BinaryHeap::printHeap(array, size, 0, 2);
    } else {
        std::cout << "BinaryHeap is empty\n";
    }

}
// 2D console print
void BinaryHeap::printHeap(int *heapArray, int heapSize, int currentNodeIndex, int levelIndent) {
    // checks whether the node index does not exceed the size of the heap
    if (currentNodeIndex >= heapSize)
        return;

    int indentIncrease = 4;
    // calls the printHeap function recursively for the right child
    printHeap(heapArray, heapSize, 2 * currentNodeIndex + 2, levelIndent + indentIncrease);
    // prints node value
    for (int j = 0; j < levelIndent; j++)
        std::cout << " ";
    std::cout << heapArray[currentNodeIndex] << "\n";
    // calls the printHeap function recursively for the left child
    printHeap(heapArray, heapSize, 2 * currentNodeIndex + 1, levelIndent + indentIncrease);

}

//bool BinaryHeap::heapTest() const {
//
//    for (int i = size - 1; i > 0; --i) {
//        int32_t parentIndex = (i - 1) / 2;
//        if (array[i] > array[parentIndex]) {
//            return false;
//        }
//    }
//    return true;
//}
