#ifndef BST_H
#define BST_H

#include <iostream>
#include <set>

class BST {
private:
    std::set<int> treeData;

    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* buildBalancedTree(const int* arr, int start, int end) const;

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
    void destroyTree(Node* node) const;
};

#endif
