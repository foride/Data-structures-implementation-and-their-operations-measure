//
// Created by Michal Lewandowski on 3/30/2023.
//

#include <iomanip>
#include "RedBlackTree.h"
// constructor, creates a Red-Black tree
// initializes the NIL color to 0 (black), the left and right pointers to nullptr, and set the root to NIL
RedBlackTree::RedBlackTree() {
    NIL = new NodeRBT;
    NIL -> color = 0;
    NIL -> left = nullptr;
    NIL -> right = nullptr;
    root = NIL;
}
// destructor, deletes whole red black tree, root and NIL
RedBlackTree::~RedBlackTree() {
    delete (root);
    delete NIL;
}

void RedBlackTree::preorder() {
    preorderPrint(this -> root);
}

void RedBlackTree::inorder() {
    inorderPrint(this -> root);
}

void RedBlackTree::postorder() {
    postorderPrint(this -> root);
}

// preorder tree traverse
// displays the value in the node, moves to the left subtree then moves to the right subtree
void RedBlackTree::preorderPrint(NodePtr node) {
    if (node != NIL) {
        std::cout << node -> data << " ";
        preorderPrint(node -> left);
        preorderPrint(node -> right);
    }
}
// inorder tree traverse
// moves to the left subtree, displays the value in the node then moves to the right subtree
void RedBlackTree::inorderPrint(NodePtr node) {
    if (node != NIL) {
        inorderPrint(node -> left);
        std::cout << node -> data << " ";
        inorderPrint(node -> right);
    }
}
// postorder tree traverse
// moves to the left subtree, moves to the right subtree then displays the value in the node
void RedBlackTree::postorderPrint(NodePtr node) {
    if (node != NIL) {
        postorderPrint(node -> left);
        postorderPrint(node -> right);
        std::cout << node -> data << " ";
    }
}

void RedBlackTree::searchTree(int k) {
    return searchTreeHelper(this -> root, k);
}

void RedBlackTree::searchTreeHelper(NodePtr node, int key) {

    NodePtr z = NIL;
    NodePtr x, y;
    while (node != NIL) {
        if (node -> data == key) {
            z = node;
        }

        if (node -> data <= key) {
            node = node -> right;
        } else {
            node = node -> left;
        }
    }

    if (z == NIL) {
        std::cout << "Key not found in the tree\n";
        return;
    } else {
        std::cout << "Key found in the tree\n";
    }
}

// repairs the tree after node deletion
void RedBlackTree::deleteFix(NodePtr x) {
    NodePtr s;
    while (x != root && x -> color == 0) {
        if (x == x -> parent -> left) {
            s = x -> parent -> right;
            if (s -> color == 1) {
                s -> color = 0;
                x -> parent -> color = 1;
                leftRotate(x -> parent);
                s = x -> parent -> right;
            }

            if (s -> left -> color == 0 && s -> right -> color == 0) {
                s -> color = 1;
                x = x -> parent;
            } else {
                if (s -> right -> color == 0) {
                    s -> left -> color = 0;
                    s -> color = 1;
                    rightRotate(s);
                    s = x -> parent -> right;
                }

                s -> color = x -> parent -> color;
                x -> parent -> color = 0;
                s -> right -> color = 0;
                leftRotate(x -> parent);
                x = root;
            }
        } else {
            s = x -> parent -> left;
            if (s -> color == 1) {
                s -> color = 0;
                x -> parent -> color = 1;
                rightRotate(x -> parent);
                s = x -> parent -> left;
            }

            if (s -> right -> color == 0) {
                s -> color = 1;
                x = x -> parent;
            } else {
                if (s -> left -> color == 0) {
                    s -> right -> color = 0;
                    s -> color = 1;
                    leftRotate(s);
                    s = x -> parent -> left;
                }

                s -> color = x -> parent -> color;
                x -> parent -> color = 0;
                s -> left -> color = 0;
                rightRotate(x -> parent);
                x = root;
            }
        }
    }
    x -> color = 0;
}

void RedBlackTree::rbTransplant(NodePtr node1, NodePtr node2) {
    if (node1 -> parent == nullptr) {
        root = node2;
    } else if (node1 == node1 -> parent -> left) {
        node1 -> parent -> left = node2;
    } else {
        node1 -> parent -> right = node2;
    }
    node2 -> parent = node1 -> parent;
}

void RedBlackTree::deleteNodeHelper(NodePtr node, int key) {
    NodePtr z = NIL;
    NodePtr x, y;
    while (node != NIL) {
        if (node -> data == key) {
            z = node;
        }

        if (node -> data <= key) {
            node = node -> right;
        } else {
            node = node -> left;
        }
    }

    if (z == NIL) {
        std::cout << "Key not found in the tree\n";
        return;
    }

    y = z;
    int y_original_color = y -> color;
    if (z -> left == NIL) {
        x = z -> right;
        rbTransplant(z, z -> right);
    } else if (z -> right == NIL) {
        x = z -> left;
        rbTransplant(z, z -> left);
    } else {
        y = minimum(z -> right);
        y_original_color = y -> color;
        x = y -> right;
        if (y -> parent == z) {
            x -> parent = y;
        } else {
            rbTransplant(y, y -> right);
            y -> right = z -> right;
            y -> right -> parent = y;
        }

        rbTransplant(z, y);
        y -> left = z -> left;
        y -> left -> parent = y;
        y -> color = z -> color;
    }
    delete z;
    if (y_original_color == 0) {
        deleteFix(x);
    }
}
// repairs the tree after node insertion
void RedBlackTree::insertFix(NodePtr k) {
    NodePtr u;
    while (k -> parent -> color == 1) {
        if (k -> parent == k -> parent -> parent -> right) {
            u = k -> parent -> parent -> left;
            if (u -> color == 1) {
                u -> color = 0;
                k -> parent -> color = 0;
                k -> parent -> parent -> color = 1;
                k = k -> parent -> parent;
            } else {
                if (k == k -> parent -> left) {
                    k = k -> parent;
                    rightRotate(k);
                }
                k -> parent -> color = 0;
                k -> parent -> parent -> color = 1;
                leftRotate(k -> parent -> parent);
            }
        } else {
            u = k -> parent -> parent -> right;

            if (u -> color == 1) {
                u -> color = 0;
                k -> parent -> color = 0;
                k -> parent -> parent -> color = 1;
                k = k -> parent -> parent;
            } else {
                if (k == k -> parent -> right) {
                    k = k -> parent;
                    leftRotate(k);
                }
                k -> parent -> color = 0;
                k -> parent -> parent -> color = 1;
                rightRotate(k -> parent -> parent);
            }
        }
        if (k == root) {
            break;
        }
    }
    root -> color = 0;
}

NodePtr RedBlackTree::minimum(NodePtr node) {
    while (node -> left != NIL) {
        node = node -> left;
    }
    return node;
}

NodePtr RedBlackTree::maximum(NodePtr node) {
    while (node -> right != NIL) {
        node = node -> right;
    }
    return node;
}

NodePtr RedBlackTree::successor(NodePtr node) {
    if (node -> right != NIL) {
        return minimum(node -> right);
    }

    NodePtr smallestGreaterNode = node -> parent;
    while (smallestGreaterNode != NIL && node == smallestGreaterNode -> right) {
        smallestGreaterNode = smallestGreaterNode -> parent;
    }
    return smallestGreaterNode;
}

NodePtr RedBlackTree::predecessor(NodePtr node) {
    if (node -> left != NIL) {
        return maximum(node -> left);
    }

    NodePtr greatestSmaller = node -> parent;
    while (greatestSmaller != NIL && node == greatestSmaller -> left) {
        greatestSmaller = greatestSmaller -> parent;
    }

    return greatestSmaller;
}
// rotates the tree relative to the selected node, left rotation
void RedBlackTree::leftRotate(NodePtr nodeRotated) {
    NodePtr rightChildOfNode = nodeRotated -> right;
    nodeRotated -> right = rightChildOfNode -> left;
    if (rightChildOfNode -> left != NIL) {
        rightChildOfNode -> left -> parent = nodeRotated;
    }
    rightChildOfNode -> parent = nodeRotated -> parent;
    if (nodeRotated -> parent == nullptr) {
        this -> root = rightChildOfNode;
    } else if (nodeRotated == nodeRotated -> parent -> left) {
        nodeRotated -> parent -> left = rightChildOfNode;
    } else {
        nodeRotated -> parent -> right = rightChildOfNode;
    }
    rightChildOfNode -> left = nodeRotated;
    nodeRotated -> parent = rightChildOfNode;
}
// rotates the tree relative to the selected node, right rotation
void RedBlackTree::rightRotate(NodePtr nodeRotated) {
    NodePtr leftChildOfNode = nodeRotated -> left;
    nodeRotated -> left = leftChildOfNode -> right;
    if (leftChildOfNode -> right != NIL) {
        leftChildOfNode -> right -> parent = nodeRotated;
    }
    leftChildOfNode -> parent = nodeRotated -> parent;
    if (nodeRotated -> parent == nullptr) {
        this -> root = leftChildOfNode;
    } else if (nodeRotated == nodeRotated -> parent -> right) {
        nodeRotated -> parent -> right = leftChildOfNode;
    } else {
        nodeRotated -> parent -> left = leftChildOfNode;
    }
    leftChildOfNode -> right = nodeRotated;
    nodeRotated -> parent = leftChildOfNode;
}
// inserts node to the RedBlackTree
void RedBlackTree::insert(int key) {
    NodePtr node = new NodeRBT;
    node -> parent = nullptr;
    node -> data = key;
    node -> left = NIL;
    node -> right = NIL;
    node -> color = 1;

    NodePtr y = nullptr;
    NodePtr x = this -> root;

    while (x != NIL) {
        y = x;
        if (node -> data < x -> data) {
            x = x -> left;
        } else {
            x = x -> right;
        }
    }

    node -> parent = y;
    if (y == nullptr) {
        root = node;
    } else if (node -> data < y -> data) {
        y -> left = node;
    } else {
        y -> right = node;
    }

    if (node -> parent == nullptr) {
        node -> color = 0;
        return;
    }

    if (node -> parent -> parent == nullptr) {
        return;
    }

    insertFix(node);
}
// returns root
NodePtr RedBlackTree::getRoot() {
    return this -> root;
}
// deletes the node with selected value
void RedBlackTree::deleteNode(int data) {
    deleteNodeHelper(this -> root, data);
}
void RedBlackTree::recursiveDisplay(NodeRBT *current, int indent) {
    std::string colorName[2] = {"B ", "R "};
    if (current != NIL) {
        recursiveDisplay(current->right, indent + 4);
        if (indent > 0) {
            std::cout << std::setw(indent) << " ";
        }
        std::cout << colorName[current->color] << current->data << "\n";
        recursiveDisplay(current->left, indent + 4);
    }
}
// 2D console print of RedBlackTree with described colors
void RedBlackTree::displayRBT() {

    RedBlackTree::recursiveDisplay(root, 15);

}
