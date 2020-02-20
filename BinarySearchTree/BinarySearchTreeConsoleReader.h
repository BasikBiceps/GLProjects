//
// Created by baxter on 20.02.20.
//

#ifndef BINARYSEARCHTREE_BINARYSEARCHTREECONSOLEREADER_H
#define BINARYSEARCHTREE_BINARYSEARCHTREECONSOLEREADER_H

#include "BinarySearchTree.h"

class BinarySearchTreeConsoleReader {
public:
    void readConsole();
    void printTree();

private:
    BinarySearchTree<int> m_bst;
};

#endif //BINARYSEARCHTREE_BINARYSEARCHTREECONSOLEREADER_H
