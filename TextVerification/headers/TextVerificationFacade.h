#ifndef TEXTVERIFICATION_TEXTVERIFICATIONFACADE_H
#define TEXTVERIFICATION_TEXTVERIFICATIONFACADE_H

#include <string>

class TextVerificationFacade
{
public:
    void TextCheckWithVectorDictionary(
            const std::string& dictionaryFilePath,
            const std::string& directoryWithTextsPath);

    void TextCheckWithHashTableDictionary(
            const std::string& dictionaryFilePath,
            const std::string& directoryWithTextsPath);

    void TextCheckWith(
            const std::string& dictionaryFilePath,
            const std::string& directoryWithTextsPath);
};

#endif //TEXTVERIFICATION_TEXTVERIFICATIONFACADE_H
