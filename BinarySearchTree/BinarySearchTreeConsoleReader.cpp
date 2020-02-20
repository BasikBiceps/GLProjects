//
// Created by baxter on 20.02.20.
//
#include <iostream>

#include "BinarySearchTreeConsoleReader.h"

void BinarySearchTreeConsoleReader::readConsole() {
    int inputNumber;
    while(std::cin >> inputNumber) {
        if (inputNumber == 0) {
            break;
        } else
            {
                m_bst.addItem(inputNumber);
            }
    }
}

void BinarySearchTreeConsoleReader::printTree() {
    m_bst.printTree(std::cout);
}
