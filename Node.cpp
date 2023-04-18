//
// Created by Michal Lewandowski on 3/27/2023.
//

#include "Node.h"

Node::Node(int32_t value, Node *prev, Node *next) {

    Node::value = value;
    Node::prev = prev;
    Node::next = next;

}
