#ifndef BST_H
#define BST_H

#include <iostream>
#include <set>
#include <vector>

/**  * @brief Klasa reprezentująca drzewo poszukiwań binarnych (BST).
 */

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
    bool remove(int val);
    void clear();
    void display(int method) const;
    bool findPath(int target, std::vector<int>& path) const;
    void destroyTree(Node* node) const;

    const std::set<int>& getData() const { return treeData; }
};

#endif
