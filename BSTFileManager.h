#ifndef BSTFILEMANAGER_H
#define BSTFILEMANAGER_H

#include <string>
#include "BST.h"

class BSTFileManager {
public:
    static bool saveToBinary(const BST& tree, const std::string& filename);

    static bool loadFromBinary(BST& tree, const std::string& filename, bool clearExisting = false);

    static bool loadFromText(BST& tree, const std::string& filename, bool clearExisting = false);
};

#endif