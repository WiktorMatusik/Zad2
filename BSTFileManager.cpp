#include "BSTFileManager.h"
#include <fstream>

using namespace std;

bool BSTFileManager::saveToBinaryFile(const BST& tree, const string& filename) {
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

bool BSTFileManager::loadFromBinaryFile(BST& tree, const string& filename, bool clearExisting) {
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

bool BSTFileManager::loadFromTextFile(BST& tree, const string& filename, bool clearExisting) {
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