#ifndef TEXTVERIFICATION_IDICTIONARYFACTORY_H
#define TEXTVERIFICATION_IDICTIONARYFACTORY_H

#include <memory>
#include <chrono>

#include "Dictionaries/IDictionary.h"
#include "Readers/IReader.h"

enum class Dictionaries
{
    VectorDictionary,
    HashTableDictionary,
    BinarySearchTreeDictionary,
    SpecHashTableDictionary,
    TrieDictionary
};

class IDictionaryFactory
{
public:
    IDictionaryFactory() = default;
    virtual ~IDictionaryFactory() = default;

    IDictionaryFactory(const IDictionaryFactory& another) = delete;
    IDictionaryFactory& operator = (const IDictionaryFactory& another) = delete;

    virtual std::unique_ptr<IDictionary> createAndFillDictionary(
            std::unique_ptr<IReader> reader,
            const Dictionaries& dictionaries,
            std::chrono::duration<double, std::milli>& duration) = 0;
};

#endif //TEXTVERIFICATION_IDICTIONARYFACTORY_H