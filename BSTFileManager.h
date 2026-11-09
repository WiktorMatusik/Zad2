#ifndef BSTFILEMANAGER_H
#define BSTFILEMANAGER_H

#include <string>
#include "BST.h"

/**  * @brief Klasa odpowiedzialna za zarządzanie plikami dla drzewa BST.
 */

class BSTFileManager {
public:
    static bool saveToBinaryFile(const BST& tree, const std::string& filename);

    static bool loadFromBinaryFile(BST& tree, const std::string& filename, bool clearExisting = false);

    static bool loadFromTextFile(BST& tree, const std::string& filename, bool clearExisting = false);
};

#endif