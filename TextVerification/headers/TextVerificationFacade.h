#ifndef TEXTVERIFICATION_TEXTVERIFICATIONFACADE_H
#define TEXTVERIFICATION_TEXTVERIFICATIONFACADE_H

#include <string>
#include <iostream>

#include "interfaces/IDictionaryFactory.h"

class TextVerificationFacade
{
public:
    static void checkText(
            const std::string& dictionaryFilePath,
            const std::string& directoryWithTextsPath,
            const Dictionaries& dictionaryType,
            std::ostream& os);
};

#endif //TEXTVERIFICATION_TEXTVERIFICATIONFACADE_H
