#include <algorithm>

#include "HashTableDictionary.h"

bool HashTableDictionary::isPresent(const std::string &value) const
{
    auto resultIterator = std::find(m_dictionary.begin(), m_dictionary.end(), value);

    return resultIterator != m_dictionary.end();
}

void HashTableDictionary::addElement(const std::string &element)
{
    m_dictionary.emplace(element);
}
