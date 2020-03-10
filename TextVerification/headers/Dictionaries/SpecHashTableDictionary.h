#ifndef TEXTVERIFICATION_SPECHASHTABLEDICTIONARY_H
#define TEXTVERIFICATION_SPECHASHTABLEDICTIONARY_H

#include "IDictionary.h"
#include "Readers/FileReader.h"
#include "DataStructures/SpecHashTable.h"

class SpecHashTableDictionary : public IDictionary
{
public:
    bool isPresent(const std::string& value) const final;
    void addElement(const std::string& element) final;

private:
    SpecHashTable m_dictionary;
};

#endif //TEXTVERIFICATION_SPECHASHTABLEDICTIONARY_H