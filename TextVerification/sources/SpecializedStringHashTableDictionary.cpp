#include "SpecializedStringHashTableDictionary.h"

bool SpecializedStringHashTableDictionary::isPresent(const std::string &value) const
{
    return m_dictionary.isPresent(value);
}

void SpecializedStringHashTableDictionary::addElement(const std::string &element)
{
    m_dictionary.addElement(element);
}
