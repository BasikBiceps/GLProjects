#ifndef TEXTVERIFICATION_TEXTCHECKER_H
#define TEXTVERIFICATION_TEXTCHECKER_H

#include <memory>
#include <chrono>
#include <fstream>

#include "Readers/IReader.h"
#include "Dictionaries/IDictionary.h"
#include "Checkers/ITextChecker.h"

class TextChecker : public ITextChecker
{
public:
    CheckerResult checkText(
            std::unique_ptr<IReader> reader,
            IDictionary& dictionary,
            std::unique_ptr<std::ofstream> outputStream) final;
};

#endif //TEXTVERIFICATION_TEXTCHECKER_H
