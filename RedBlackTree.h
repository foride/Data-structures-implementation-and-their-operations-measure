//
// Created by Michal Lewandowski on 3/30/2023.
//

#ifndef SDIZO_REDBLACKTREE_H
#define SDIZO_REDBLACKTREE_H

#include <iostream>

struct NodeRBT {
    int data;
    NodeRBT *parent;
    NodeRBT *left;
    NodeRBT *right;
    int color;
};

typedef NodeRBT *NodePtr;

class RedBlackTree {
private:
    NodePtr root;
    NodePtr NIL;

    void preorderPrint(NodePtr node);

    void inorderPrint(NodePtr node);

    void postorderPrint(NodePtr node);

    void searchTreeHelper(NodePtr node, int key);

    void deleteFix(NodePtr x);

    void rbTransplant(NodePtr u, NodePtr v);

    void deleteNodeHelper(NodePtr node, int key);

    void insertFix(NodePtr k);

    NodePtr minimum(NodePtr node);

    NodePtr maximum(NodePtr node);

    NodePtr successor(NodePtr node);

    NodePtr predecessor(NodePtr node);

    void leftRotate(NodePtr nodeRotated);

    void rightRotate(NodePtr nodeRotated);

    void recursiveDisplay(NodeRBT *current, int indent);

    NodePtr getRoot();
public:
    RedBlackTree();

    ~RedBlackTree();

    void preorder();

    void inorder();

    void postorder();

    void insert(int key);

    void deleteNode(int data);

    void searchTree(int k);

    void displayRBT();
};


#endif //SDIZO_REDBLACKTREE_H
