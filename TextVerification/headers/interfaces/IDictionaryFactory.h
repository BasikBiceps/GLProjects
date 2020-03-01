#ifndef TEXTVERIFICATION_IDICTIONARYFACTORY_H
#define TEXTVERIFICATION_IDICTIONARYFACTORY_H

#endif //TEXTVERIFICATION_IDICTIONARYFACTORY_H

#include <memory>
#include <chrono>

#include "interfaces/IDictionary.h"
#include "interfaces/IReader.h"

enum class Dictionaries
{
    VectorDictionary,
    HashTableDictionary
};

class IDictionaryFactory
{
public:
    virtual std::shared_ptr<IDictionary> createDictionary(
            std::unique_ptr<IReader> reader,
            const Dictionaries& dictionaries,
            std::chrono::duration<double, std::milli>& duration) = 0;
};