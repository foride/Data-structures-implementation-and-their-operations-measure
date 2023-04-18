//
// Created by Michal Lewandowski on 3/27/2023.
//

#ifndef SDIZO_DOUBLYLINKEDLIST_H
#define SDIZO_DOUBLYLINKEDLIST_H


#include <cstdint>
#include "Node.h"

class DoublyLinkedList {

public:

    int size;
    Node *head;
    Node *tail;

    DoublyLinkedList();

    ~DoublyLinkedList();

    void insertHead(int32_t number);

    void removeHead();

    void insertTail(int32_t number);

    void removeTail();

    void insert(int32_t number, int index);

    void remove(int index);

    void displayList() const;

    bool isNumberInList(int32_t number) const;

    void displayListBackward() const;
};


#endif //SDIZO_DOUBLYLINKEDLIST_H
