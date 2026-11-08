#include "BSTFileManager.h"
#include <fstream>

using namespace std;

<<<<<<< HEAD
bool BSTFileManager::saveToBinaryFile(const BST& tree, const string& filename) {
=======
bool BSTFileManager::saveToBinary(const BST& tree, const string& filename) {
>>>>>>> 821c108c28b88c8721cedd293089b3367d179472
    ofstream file(filename, ios::binary);
    if (!file.is_open()) return false;

    const auto& data = tree.getData();
    size_t count = data.size();

    file.write(reinterpret_cast<const char*>(&count), sizeof(count));

    for (int val : data) {
        file.write(reinterpret_cast<const char*>(&val), sizeof(val));
    }

    file.close();
    return true;
}

<<<<<<< HEAD
bool BSTFileManager::loadFromBinaryFile(BST& tree, const string& filename, bool clearExisting) {
=======
bool BSTFileManager::loadFromBinary(BST& tree, const string& filename, bool clearExisting) {
>>>>>>> 821c108c28b88c8721cedd293089b3367d179472
    ifstream file(filename, ios::binary);
    if (!file.is_open()) return false;

    if (clearExisting) {
        tree.clear();
    }

    size_t count = 0;
    file.read(reinterpret_cast<char*>(&count), sizeof(count));

    for (size_t i = 0; i < count; ++i) {
        int val;
        file.read(reinterpret_cast<char*>(&val), sizeof(val));
        tree.add(val);
    }

    file.close();
    return true;
}

<<<<<<< HEAD
bool BSTFileManager::loadFromTextFile(BST& tree, const string& filename, bool clearExisting) {
=======
bool BSTFileManager::loadFromText(BST& tree, const string& filename, bool clearExisting) {
>>>>>>> 821c108c28b88c8721cedd293089b3367d179472
    ifstream file(filename);
    if (!file.is_open()) return false;

    if (clearExisting) {
        tree.clear();
    }

    int val;
    while (file >> val) {
        tree.add(val);
    }

    file.close();
    return true;
}