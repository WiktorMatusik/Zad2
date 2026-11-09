#include "BST.h"
#include <iostream>
#include <vector>
using namespace std;

BST::BST() {}

BST::~BST() {
    clear();
}

/**  * @brief Dodaje wartość do drzewa.
 * @param val Wartość do dodania.
 */

void BST::add(int val) {
    treeData.insert(val);
}

/**  * @brief Usuwa wartość z drzewa.
 * @param val Wartość do usunięcia.
 * @return true, jeśli wartość została usunięta, false w przeciwnym razie.
 */
bool BST::remove(int val) {
    return treeData.erase(val) > 0;
}
/**  * @brief Niszczy drzewo.
 * @param node Wskaźnik do korzenia drzewa.
 */
void BST::destroyTree(Node* node) const{
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

/**  * @brief Czyści drzewo.
 */
void BST::clear() {
    treeData.clear();
}

/**  * @brief Buduje zrównoważone drzewo z tablicy.
 * @param arr Tablica wartości.
 * @param start Indeks początkowy.
 * @param end Indeks końcowy.
 * @return Wskaźnik do korzenia drzewa.
 */
BST::Node* BST::buildBalancedTree(const int* arr, int start, int end) const {
    if (start > end) return nullptr;
    int mid = start + (end - start) / 2;
    Node* node = new Node(arr[mid]);
    node->left = buildBalancedTree(arr, start, mid - 1);
    node->right = buildBalancedTree(arr, mid + 1, end);
    return node;
}
/**  * @brief znajduje ścieżkę do wartości w drzewie.
 * @param target Wartość, dla której szukamy ścieżki.
 * @param path Wektor do przechowywania ścieżki.
 * @return true, jeśli ścieżka została znaleziona, false w przeciwnym razie.
 */
bool BST::findPath(int target, std::vector<int>& path) const {
    path.clear();
    if (treeData.empty()) {
        return false;
    }

    vector<int> vec(treeData.begin(), treeData.end());
    Node* tempRoot = buildBalancedTree(vec.data(), 0, static_cast<int>(vec.size()) - 1);

    Node* current = tempRoot;
    bool found = false;

    while (current != nullptr) {
        path.push_back(current->data);

        if (current->data == target) {
            found = true;
            break;
        }
        else if (target < current->data) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    if (!found) {
        path.clear();
    }

    destroyTree(tempRoot);

    return found;
}
/**  * @brief Wypisuje wartości drzewa w kolejności preorder.
 * @param node Wskaźnik do węzła.
 */
void BST::printPreorder(Node* node) const {
    if (!node) return;
    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}
/**  * @brief Wypisuje wartości drzewa w kolejności inorder.
 * @param node Wskaźnik do węzła.
 */
void BST::printInorder(Node* node) const {
    if (!node) return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
/**  * @brief Wypisuje wartości drzewa w kolejności postorder.
 * @param node Wskaźnik do węzła.
 */
void BST::printPostorder(Node* node) const {
    if (!node) return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}
/**  * @brief Wypisuje drzewo w formie graficznej.
 * @param node Wskaźnik do węzła.
 * @param space Odległość od lewej krawędzi.
 */
void BST::printGraphical(Node* node, int space) const {
    if (!node) return;
    space += 5;
    printGraphical(node->right, space);
    cout << endl;
    for (int i = 5; i < space; i++) cout << " ";
    cout << node->data << "\n";
    printGraphical(node->left, space);
}
/**  * @brief Wyświetla drzewo w zależności od wybranej metody.
 * @param method Metoda wyświetlania (1 - preorder, 2 - inorder, 3 - postorder, 4 - graficznie).
 */
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
    