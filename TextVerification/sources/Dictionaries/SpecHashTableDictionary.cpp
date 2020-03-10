#include "Dictionaries/SpecHashTableDictionary.h"

bool SpecHashTableDictionary::isPresent(const std::string &value) const
{
    return m_dictionary.isPresent(value);
}

void SpecHashTableDictionary::addElement(const std::string &element)
{
    m_dictionary.addElement(element);
}
