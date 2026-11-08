#ifndef BSTFILEMANAGER_H
#define BSTFILEMANAGER_H

#include <string>
#include "BST.h"

class BSTFileManager {
public:
<<<<<<< HEAD
    static bool saveToBinaryFile(const BST& tree, const std::string& filename);

    static bool loadFromBinaryFile(BST& tree, const std::string& filename, bool clearExisting = false);

    static bool loadFromTextFile(BST& tree, const std::string& filename, bool clearExisting = false);
=======
    static bool saveToBinary(const BST& tree, const std::string& filename);

    static bool loadFromBinary(BST& tree, const std::string& filename, bool clearExisting = false);

    static bool loadFromText(BST& tree, const std::string& filename, bool clearExisting = false);
>>>>>>> 821c108c28b88c8721cedd293089b3367d179472
};

#endif