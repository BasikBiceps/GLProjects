#include "Dictionaries/VectorDictionary.h"
#include <algorithm>

void VectorDictionary::addElement(const std::string& element)
{
    m_dictionary.push_back(element);
}

bool VectorDictionary::isPresent(const std::string& value) const
{
    auto resultIterator = std::find(m_dictionary.begin(), m_dictionary.end(), value);

    return resultIterator != m_dictionary.end();
}
