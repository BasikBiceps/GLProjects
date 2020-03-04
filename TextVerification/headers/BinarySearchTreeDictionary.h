#ifndef TEXTVERIFICATION_BINARYSEARCHTREEDICTIONARY_H
#define TEXTVERIFICATION_BINARYSEARCHTREEDICTIONARY_H

#include <string>

#include "SpecializedStringBinarySearchTree.h"
#include "interfaces/IDictionary.h"
#include "FileReader.h"

class BinarySearchTreeDictionary : public IDictionary
{
public:
    bool isPresent(const std::string& value) const final;
    void addElement(const std::string& element) final;

private:
    SpecializedStringBinarySearchTree m_dictionary;
};

#endif //TEXTVERIFICATION_BINARYSEARCHTREEDICTIONARY_H
