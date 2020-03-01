#include "DictionaryFactory.h"
#include "VectorDictionary.h"
#include "HashTableDictionary.h"

std::shared_ptr<IDictionary> DictionaryFactory::createDictionary(
        std::unique_ptr<IReader> reader,
        const Dictionaries &dictionaries,
        std::chrono::duration<double, std::milli>& duration)
{
    {
        std::shared_ptr<IDictionary> resultDictionary;

        switch (dictionaries)
        {
            case Dictionaries::VectorDictionary :
                resultDictionary = std::make_shared<VectorDictionary>();
                break;
            case Dictionaries::HashTableDictionary :
                resultDictionary = std::make_shared<HashTableDictionary>();
                break;
            default:
                return resultDictionary;
        }

        auto startFill = std::chrono::high_resolution_clock::now();
        std::string word = reader->readNext();

        while (word != "")
        {
            resultDictionary->addElement(word);
            word = reader->readNext();
        }

        auto stopFill = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(stopFill - startFill);

        return resultDictionary;
    }
}
