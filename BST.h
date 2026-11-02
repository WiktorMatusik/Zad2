#ifndef BST_H
#define BST_H

#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int val);
    void destroyTree(Node* node);

    void printPreorder(Node* node) const;
    void printInorder(Node* node) const;
    void printPostorder(Node* node) const;
    void printGraphical(Node* node, int space) const;

public:
    BST();
    ~BST();

    void add(int val);
    void clear();
    void display(int method) const;
};

#endif
