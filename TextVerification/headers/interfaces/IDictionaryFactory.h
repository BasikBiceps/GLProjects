#ifndef TEXTVERIFICATION_IDICTIONARYFACTORY_H
#define TEXTVERIFICATION_IDICTIONARYFACTORY_H

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
    IDictionaryFactory() = default;
    virtual ~IDictionaryFactory() = default;

    IDictionaryFactory(const IDictionaryFactory& another) = delete;
    IDictionaryFactory& operator = (const IDictionaryFactory& another) = delete;

    virtual std::shared_ptr<IDictionary> createDictionary(
            std::unique_ptr<IReader> reader,
            const Dictionaries& dictionaries,
            std::chrono::duration<double, std::milli>& duration) = 0;
};

#endif //TEXTVERIFICATION_IDICTIONARYFACTORY_H