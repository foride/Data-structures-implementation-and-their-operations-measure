//
// Created by Michal Lewandowski on 3/27/2023.
//

#ifndef SDIZO_NODE_H
#define SDIZO_NODE_H


#include <cstdint>

class Node {

public:
    Node *prev;
    Node *next;
    int32_t value;

    Node(int32_t value, Node *prev, Node *next);
};


#endif //SDIZO_NODE_H
