#ifndef TEXTVERIFICATION_IDICTIONARY_H
#define TEXTVERIFICATION_IDICTIONARY_H

#include <string>

class IDictionary
{
public:
    IDictionary() = default;
    virtual ~IDictionary() = default;

    virtual bool isPresent(const std::string& value) const = 0;
    virtual void addElement(const std::string& element) = 0;
};

#endif //TEXTVERIFICATION_IDICTIONARY_H
