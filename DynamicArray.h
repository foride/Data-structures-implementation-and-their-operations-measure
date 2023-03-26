//
// Created by Michal Lewandowski on 3/26/2023.
//

#ifndef SDIZO_DYNAMICARRAY_H
#define SDIZO_DYNAMICARRAY_H

#include <cstdint>

class DynamicArray {

public:

    int *head{};
    int *tail{};
    int size{};

    DynamicArray();

    ~DynamicArray();

    void insertHead(int32_t number);

    void insertTail(int32_t number);

    void insert(int32_t number, int arrayIndex);

    void removeHead();

    void removeTail();

    void remove(int arrayIndex);

    void displayArray() const;

    bool isNumberInArray(int32_t number) const;

};

#endif //SDIZO_DYNAMICARRAY_H
