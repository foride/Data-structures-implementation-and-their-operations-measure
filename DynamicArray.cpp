//
// Created by Michal Lewandowski on 3/26/2023.
//

#include "DynamicArray.h"
#include <iostream>

using namespace std;

DynamicArray::DynamicArray() {

    int32_t *head = nullptr;
    int32_t *tail = nullptr;
    int size = 0;
}

DynamicArray::~DynamicArray() {

    delete[]head;

}

void DynamicArray::insertHead(int32_t number) {

    int32_t *newHead = new int32_t[size + 1];

    newHead[0] = number;

    for (int i = 1; i <= size; i++) {
        newHead[i] = head[i - 1];
    }

    delete head;
    head = newHead;
    tail = &head[size];
    cout << tail << " < tail\n";
    cout << head << " <head\n";
    size++;

}

void DynamicArray::insertTail(int32_t number) {

    int32_t *newHead = new int32_t[size + 1];
    newHead[size] = number;

    for (int i = 0; i < size; i++) {
        newHead[i] = head[i];
    }
    delete head;
    head = newHead;
    tail = &head[size];
    cout << tail << " < tail a\n";
    cout << head << " <head a\n";
    size++;

}

void DynamicArray::insert(int32_t number, int arrayIndex) {

    if (arrayIndex >= 0 && arrayIndex <= size) {
        int32_t *newHead = new int32_t[size + 1];

        int j = 0;
        for (int i = 0; i <= size; i++) {
            if (arrayIndex == i) {
                newHead[i] = number;

            } else {
                newHead[i] = head[j];
                j++;
            }
            cout << newHead[i] << " petla\n";
        }

        delete head;
        head = newHead;
        tail = &head[size];
        cout << tail << " < tail a\n";
        cout << head << " <head a\n";
        size++;
    } else {
        cout << "Index must be positive number and be equal or lower than array size! ";
    }

}

void DynamicArray::removeHead() {
    if (size > 0) {
        int32_t *newHead = new int32_t[size - 1];

        for (int i = 1; i <= size; i++) {
            newHead[i - 1] = head[i];
        }

        delete head;
        head = newHead;
        tail = &head[size];
        size--;
    } else {
        cout << "Array is empty" << "\n";
    }

}

void DynamicArray::removeTail() {
    if (size > 0) {
        int32_t *newHead = new int32_t[size - 1];

        for (int i = 0; i < size - 1; i++) {
            newHead[i] = head[i];
        }

        delete head;
        head = newHead;
        tail = &head[size];
        size--;
    } else {
        cout << "Array is empty" << "\n";
    }

}

void DynamicArray::remove(int arrayIndex)  {
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
