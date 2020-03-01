#ifndef TEXTVERIFICATION_DICTIONARYFACTORY_H
#define TEXTVERIFICATION_DICTIONARYFACTORY_H

#include "interfaces/IDictionaryFactory.h"

class DictionaryFactory : public IDictionaryFactory
{
public:
    std::shared_ptr<IDictionary> createDictionary(
            std::unique_ptr<IReader> reader, 
            const Dictionaries& dictionaries, 
            std::chrono::duration<double, std::milli>& duration) final;
};

#endif //TEXTVERIFICATION_DICTIONARYFACTORY_H
