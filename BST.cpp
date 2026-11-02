#include "BST.h"
#include <iostream>

using namespace std;

BST::BST() : root(nullptr) {}

BST::~BST() {
    clear();
}

Node* BST::insert(Node* node, int val) {
    if (!node) return new Node(val);
    if (val < node->data)
        node->left = insert(node->left, val);
    else if (val > node->data)
        node->right = insert(node->right, val);
    return node;
}

void BST::add(int val) {
    root = insert(root, val);
}

void BST::destroyTree(Node* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

void BST::clear() {
    destroyTree(root);
    root = nullptr;
}

void BST::printPreorder(Node* node) const {
    if (!node) return;
    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

void BST::printInorder(Node* node) const {
    if (!node) return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

void BST::printPostorder(Node* node) const {
    if (!node) return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}

void BST::printGraphical(Node* node, int space) const {
    if (!node) return;
    space += 5;
    printGraphical(node->right, space);
    cout << endl;
    for (int i = 5; i < space; i++) cout << " ";
    cout << node->data << "\n";
    printGraphical(node->left, space);
}

void BST::display(int method) const {
    if (!root) {
        cout << "Drzewo jest puste.\n";
        return;
    }
    switch (method) {
    case 1: cout << "Preorder: "; printPreorder(root); cout << "\n"; break;
    case 2: cout << "Inorder: "; printInorder(root); cout << "\n"; break;
    case 3: cout << "Postorder: "; printPostorder(root); cout << "\n"; break;
    case 4: cout << "Graficznie:\n"; printGraphical(root, 0); cout << "\n"; break;
    default: cout << "Nieznana metoda.\n";
    }
}
