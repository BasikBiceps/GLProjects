#include "Dictionaries/BinarySearchTreeDictionary.h"

bool BinarySearchTreeDictionary::isPresent(const std::string &value) const
{
    return m_dictionary.isPresent(value);
}

void BinarySearchTreeDictionary::addElement(const std::string &element)
{
    m_dictionary.addElement(element);
}

