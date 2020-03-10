#ifndef TEXTVERIFICATION_HASHTABLEDICTIONARY_H
#define TEXTVERIFICATION_HASHTABLEDICTIONARY_H

#include <unordered_set>

#include "IDictionary.h"

class HashTableDictionary : public IDictionary
{
public:
    bool isPresent(const std::string& value) const final;
    void addElement(const std::string& element) final;

private:
    std::unordered_set<std::string> m_dictionary;
};

#endif //TEXTVERIFICATION_HASHTABLEDICTIONARY_H
