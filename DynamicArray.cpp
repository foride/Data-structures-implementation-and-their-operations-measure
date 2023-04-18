//
// Created by Michal Lewandowski on 3/26/2023.
//

#include "DynamicArray.h"
#include <iostream>

using namespace std;

// no-argument constructor initializing variable head pointer to null and size to zero
DynamicArray::DynamicArray() {

    int32_t *head = nullptr;
    int size = 0;
}
// destructor, deletes head array
DynamicArray::~DynamicArray() {

    delete[]head;

}
// inserts an element at the beginning of a dynamic array
void DynamicArray::insertHead(int32_t number) {
    // creates a new dynamic array with a size increased by one
    int32_t *newHead = new int32_t[size + 1];

    newHead[0] = number;
    // copies the elements of the old dynamic array to the new one
    for (int i = 1; i <= size; i++) {
        newHead[i] = head[i - 1];
    }
    // deletes the old dynamic array and assigns the new one to the head pointer
    delete head;
    head = newHead;
    size++;

}
// inserts an element at the end of a dynamic array
void DynamicArray::insertTail(int32_t number) {
    // creates a new dynamic array with a size increased by one
    int32_t *newHead = new int32_t[size + 1];
    newHead[size] = number;
    // copies the elements of the old dynamic array to the new one
    for (int i = 0; i < size; i++) {
        newHead[i] = head[i];
    }
    // deletes the old dynamic array and assigns the new one to the head pointer
    delete head;
    head = newHead;
    size++;

}
// puts an element at the selected dynamic array index
void DynamicArray::insert(int32_t number, int arrayIndex) {
    // creates a new dynamic array with a size increased by one
    if (arrayIndex >= 0 && arrayIndex <= size) {
        int32_t *newHead = new int32_t[size + 1];

        int j = 0;
        // copies the elements of the old dynamic array to the new one
        for (int i = 0; i <= size; i++) {
            if (arrayIndex == i) {
                newHead[i] = number;

            } else {
                newHead[i] = head[j];
                j++;
            }
        }
        // deletes the old dynamic array and assigns the new one to the head pointer
        delete head;
        head = newHead;
        size++;
    } else {
        cout << "Index must be positive number and be equal or lower than array size! ";
    }

}
// removes the element from the beginning of the dynamic array
void DynamicArray::removeHead() {
    if (size > 0) {
        int32_t *newHead = new int32_t[size - 1];

        for (int i = 1; i <= size; i++) {
            newHead[i - 1] = head[i];
        }

        delete head;
        head = newHead;
        size--;
    } else {
        cout << "Array is empty" << "\n";
    }

}
// removes the element at the end of the dynamic array
void DynamicArray::removeTail() {
    if (size > 0) {
        int32_t *newHead = new int32_t[size - 1];

        for (int i = 0; i < size - 1; i++) {
            newHead[i] = head[i];
        }

        delete head;
        head = newHead;
        size--;
    } else {
        cout << "Array is empty" << "\n";
    }

}
// removes the element at the selected dynamic array index
void DynamicArray::remove(int arrayIndex)  {
    // checks if there is at least one element in the array and if the given index is valid
    if (size > 0 && arrayIndex >= 0 && arrayIndex < size) {

        int *newHead = new int[size - 1];

        for (int i = 0; i < arrayIndex; i++) {
            newHead[i] = head[i];
        }

        for (int i = arrayIndex; i < size - 1; i++) {
            newHead[i] = head[i + 1];
        }

        delete[] head;
        head = newHead;

        size--;
    } else {
        cout << "There is no element with index: [" << arrayIndex << "]!" << "\n";
    }

}
// displays an array (console display)
void DynamicArray::displayArray() const {
    if (size > 0) {
        cout << "[ ";
        for (int i = 0; i < size; i++) {
            cout << head[i] << ", ";
        }
        cout << "]" << "\n";
    } else {
        cout << "Array is empty" << "\n";
    }
}
// checks if an element with the given value exists in the array
bool DynamicArray::isNumberInArray(int32_t number) const {
    for (int i = 0; i < size; i++) {
        if (head[i] == number) {
            cout << "This number exists in array with index: [" << i << "]" << "\n";
            return true;
        }
    }
    cout << "This element doesnt exist in array" << "\n";
    return false;
}
