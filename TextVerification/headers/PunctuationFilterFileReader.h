#ifndef TEXTVERIFICATION_PUNCTUATIONFILTERFILEREADER_H
#define TEXTVERIFICATION_PUNCTUATIONFILTERFILEREADER_H

#include <string>
#include <memory>
#include <fstream>
#include <sstream>

#include "interfaces/IReader.h"

class PunctuationFilterFileReader : public IReader
{
public:
    explicit PunctuationFilterFileReader(const std::string& filePath);

    std::string readNext() final;

private:
    bool isRightSymbol(char symbol);

private:
    std::unique_ptr<std::ifstream> m_inputStream;
    std::string m_filePath;
    std::stringstream m_stringstream;
};

#endif //TEXTVERIFICATION_PUNCTUATIONFILTERFILEREADER_H
