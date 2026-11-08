#include "BST.h"
#include <iostream>
#include <vector>
using namespace std;

BST::BST() {}

BST::~BST() {
    clear();
}

void BST::add(int val) {
    treeData.insert(val);
}

void BST::destroyTree(Node* node) const{
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

void BST::clear() {
    treeData.clear();
}

BST::Node* BST::buildBalancedTree(const int* arr, int start, int end) const {
    if (start > end) return nullptr;
    int mid = start + (end - start) / 2;
    Node* node = new Node(arr[mid]);
    node->left = buildBalancedTree(arr, start, mid - 1);
    node->right = buildBalancedTree(arr, mid + 1, end);
    return node;
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
    if (treeData.empty()) {
        cout << "Drzewo jest puste.\n";
        return;
    }

    vector<int> vec(treeData.begin(), treeData.end());
    Node* tempRoot = buildBalancedTree(vec.data(), 0, static_cast<int>(vec.size()) - 1);

    switch (method) {
    case 1: cout << "Preorder: "; printPreorder(tempRoot); cout << "\n"; break;
    case 2: cout << "Inorder: "; printInorder(tempRoot); cout << "\n"; break;
    case 3: cout << "Postorder: "; printPostorder(tempRoot); cout << "\n"; break;
    case 4: cout << "Graficznie:\n"; printGraphical(tempRoot, 0); cout << "\n"; break;
    default: cout << "Nieznana metoda.\n";
    }
    destroyTree(tempRoot);
}
    