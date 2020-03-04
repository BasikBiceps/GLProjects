#ifndef TEXTVERIFICATION_SPECIALIZEDSTRINGHASHTABLEDICTIONARY_H
#define TEXTVERIFICATION_SPECIALIZEDSTRINGHASHTABLEDICTIONARY_H

#include "interfaces/IDictionary.h"
#include "FileReader.h"
#include "SpecializedStringHashTable.h"

class SpecializedStringHashTableDictionary : public IDictionary
{
public:
    bool isPresent(const std::string& value) const final;
    void addElement(const std::string& element) final;

private:
    SpecializedStringHashTable m_dictionary;
};

#endif //TEXTVERIFICATION_SPECIALIZEDSTRINGHASHTABLEDICTIONARY_H