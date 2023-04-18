//
// Created by Michal Lewandowski on 3/27/2023.
//

#include "DoublyLinkedList.h"
#include <iostream>
// no-argument constructor initializing head and tail variable pointer to null and size to zero
DoublyLinkedList::DoublyLinkedList() {

    DoublyLinkedList::size = 0;
    DoublyLinkedList::head = nullptr;
    DoublyLinkedList::tail = nullptr;

}
// destructor
DoublyLinkedList::~DoublyLinkedList() {

    while (head != tail) {
        head = head->next; // sets the head of the list to the next item
        delete head->prev; // removes the previous item
    }
    delete tail; // removes the tail of the list

}
// inserts an element at the beginning of a dynamic DoublyLinkedList
void DoublyLinkedList::insertHead(int32_t number) {
    // creates a new node with a value, the previous element set to nullptr, and the next element set to the head of the list
    Node *newNode = new Node(number, nullptr, nullptr);
    newNode -> next = head;

    if (head != nullptr) {
        head -> prev = newNode;
    } else {
        tail = newNode;
    }

    head = newNode;
    size++;
}
// inserts the element at the end of DoublyLinkedList
void DoublyLinkedList::insertTail(int32_t number) {

    Node *newTail = new Node(number, nullptr, nullptr);
    newTail -> prev = tail;
    if (tail != nullptr) {
        tail -> next = newTail;
    } else {
        head = newTail;
    }
    tail = newTail;
    size++;

}
// removes the element from the beginning of the dynamic DoublyLinkedList
void DoublyLinkedList::removeHead() {

    if (head != nullptr) {

        Node *newHead = head -> next;
        head = newHead;
        newHead -> prev = nullptr;
        size--;

    } else {
        std::cout << "The linkedList is empty!\n";
    }

}
// removes the element at the end of DoublyLinkedList
void DoublyLinkedList::removeTail() {

    if (tail != nullptr) {

        tail -> prev -> next = nullptr;
        Node *newTail = tail -> prev;
        tail = newTail;
        size--;

    } else {
        std::cout << "The linkedList is empty!\n";
    }

}
// puts an element at the selected DoublyLinkedList index
void DoublyLinkedList::insert(int32_t number, int index) {

    if (index < 0 || index > size) {
        // checks if the index is valid
        std::cout << "Index: " << index << " doesn't exist in this LinkedList\n";
        return;

    } else if (index == 0) {
        // inserts the node at the top of the list
        insertHead(number);
        return;

    } else if (index == size) {
        // inserts the node at the end of the list
        insertTail(number);
        return;

    } else {
        Node *newNode = new Node(number, nullptr, nullptr);

        if ( (size / 2) > index ) {
            Node *tempNodePointer = head;
            for (int i = 0; i < index; i++) {
                tempNodePointer = tempNodePointer -> next;
            }
            newNode -> prev = tempNodePointer -> prev;
            newNode -> next = tempNodePointer;
            tempNodePointer -> prev -> next = newNode;
            tempNodePointer -> prev = newNode;
        } else {
            Node *tempNodePointer = tail;
            for (int i = size; i > size; i--) {
                tempNodePointer = tempNodePointer -> prev;
            }
            newNode -> prev = tempNodePointer -> prev;
            newNode -> next = tempNodePointer;
            tempNodePointer -> prev -> next = newNode;
            tempNodePointer -> prev = newNode;

        }
        size++;

    }

}
// removes the element at the selected DoublyLinkedList index
void DoublyLinkedList::remove(int index) {
    // if the index is less than zero or greater than the size of the list, print a message and exit the function
    if (index < 0 || index > size) {
        std::cout << "There is no element with index: " << index << "]\n";
        return;
    } else if  (index == 0) {
        // if the index is zero, call removeHead() and exit the function
        removeHead();
        return;
    } else if (index == size - 1) {
        // if the index is size - 1, call removeTail() and terminate the function
        removeTail();
        return;
    } else {
        // otherwise, find the item at the given index and delete it
        if ( (size / 2) > index ) {
            // start searching for specific value from the beginning
            Node *tempNodePointer = head;
            for (int i = 0; i < index; i++) {
                tempNodePointer = tempNodePointer -> next;
            }
            tempNodePointer -> prev -> next = tempNodePointer -> next;
            tempNodePointer -> next -> prev = tempNodePointer -> prev;


        } else {
            // start searching for specific value from the end
            Node *tempNodePointer = tail;
            for (int i = size - 1; i > index; i--) {

                tempNodePointer = tempNodePointer -> prev;
            }
                tempNodePointer -> prev -> next = tempNodePointer -> next;
                tempNodePointer -> next -> prev = tempNodePointer -> prev;

        }
        size--;

    }

}
// checks if an element with the given value exists in the array
bool DoublyLinkedList::isNumberInList(int32_t number) const {

    if (head != nullptr) {
        Node *tempNode = head;
        while (tempNode->value != number) {
            tempNode = tempNode->next;
            if (!tempNode) {
                return false;
            }
        }
        std::cout << "This value exists in the LinkedList\n";
        return true;
    } else {
        std::cout << "The linkedList is empty!\n";
        return false;
    }

}
// prints the contents of the list from beginning to end
void DoublyLinkedList::displayList() const {

    if (head != nullptr) {
        Node *tempNode = head;
        while (tempNode != nullptr) {
            std::cout << tempNode->value << " ";
            tempNode = tempNode->next;
        }
        std::cout << "\n";
    } else {
        std::cout << "The linkedList is empty!\n";
    }

}
// prints the contents of the list from end to beginning
void DoublyLinkedList::displayListBackward() const {
    if (head != nullptr) {
        Node *tempNode = tail;
        while (tempNode != nullptr) {
            std::cout << tempNode->value << " ";
            tempNode = tempNode->prev;
        }
    } else {
        std::cout << "List is empty\n";
    }
}

