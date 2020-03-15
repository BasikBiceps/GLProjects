#include "Dictionaries/TrieDictionary.h"

void TrieDictionary::addElement(const std::string& element)
{
    m_dictionary.addElement(element);
}

bool TrieDictionary::isPresent(const std::string& value) const
{
    return  m_dictionary.isPresent(value);
}
