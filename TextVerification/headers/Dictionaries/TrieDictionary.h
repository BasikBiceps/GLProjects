#ifndef TEXTVERIFICATION_TRIEDICTIONARY_H
#define TEXTVERIFICATION_TRIEDICTIONARY_H

#include "DataStructures/Trie.h"
#include "IDictionary.h"

class TrieDictionary : public IDictionary
{
public:
    bool isPresent(const std::string& value) const final;
    void addElement(const std::string& element) final;

private:
    Trie m_dictionary;
};

#endif //TEXTVERIFICATION_TRIEDICTIONARY_H
