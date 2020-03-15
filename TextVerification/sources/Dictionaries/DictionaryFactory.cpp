#include "Dictionaries/DictionaryFactory.h"
#include "Dictionaries/VectorDictionary.h"
#include "Dictionaries/HashTableDictionary.h"
#include "Dictionaries/BinarySearchTreeDictionary.h"
#include "Dictionaries/SpecHashTableDictionary.h"
#include "Dictionaries/TrieDictionary.h"

std::unique_ptr<IDictionary> DictionaryFactory::createAndFillDictionary(
        std::unique_ptr<IReader> reader,
        const Dictionaries &dictionaries,
        std::chrono::duration<double, std::milli>& duration)
{
    {
        std::unique_ptr<IDictionary> resultDictionary;

        switch (dictionaries)
        {
            case Dictionaries::VectorDictionary :
                resultDictionary = std::make_unique<VectorDictionary>();
                break;
            case Dictionaries::HashTableDictionary :
                resultDictionary = std::make_unique<HashTableDictionary>();
                break;
            case Dictionaries::BinarySearchTreeDictionary :
                resultDictionary = std::make_unique<BinarySearchTreeDictionary>();
                break;
            case Dictionaries::SpecHashTableDictionary :
                resultDictionary = std::make_unique<SpecHashTableDictionary>();
                break;
            case Dictionaries::TrieDictionary :
                resultDictionary = std::make_unique<TrieDictionary>();
                break;
            default:
                return resultDictionary;
        }

        auto startFill = std::chrono::high_resolution_clock::now();
        std::string word = reader->readNext();

        while (word != "EOF")
        {
            resultDictionary->addElement(word);
            word = reader->readNext();
        }

        auto stopFill = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(stopFill - startFill);

        return resultDictionary;
    }
}