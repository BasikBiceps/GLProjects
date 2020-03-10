#ifndef TEXTVERIFICATION_VECTORDICTIONARY_H
#define TEXTVERIFICATION_VECTORDICTIONARY_H

#include <vector>

#include "IDictionary.h"
#include "Readers/FileReader.h"

class VectorDictionary : public IDictionary
{
public:
    bool isPresent(const std::string& value) const final;
    void addElement(const std::string& element) final;

private:
    std::vector<std::string> m_dictionary;
};

#endif //TEXTVERIFICATION_VECTORDICTIONARY_H
