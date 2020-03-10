#ifndef TEXTVERIFICATION_BINARYSEARCHTREEDICTIONARY_H
#define TEXTVERIFICATION_BINARYSEARCHTREEDICTIONARY_H

#include <string>

#include "DataStructures/BinarySearchTree.h"
#include "IDictionary.h"
#include "Readers/FileReader.h"

class BinarySearchTreeDictionary : public IDictionary
{
public:
    bool isPresent(const std::string& value) const final;
    void addElement(const std::string& element) final;

private:
    BinarySearchTree m_dictionary;
};

#endif //TEXTVERIFICATION_BINARYSEARCHTREEDICTIONARY_H
