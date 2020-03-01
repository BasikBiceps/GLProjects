#ifndef TEXTVERIFICATION_TEXTCHECKER_H
#define TEXTVERIFICATION_TEXTCHECKER_H

#include <memory>
#include <chrono>
#include <fstream>

#include "interfaces/IReader.h"
#include "interfaces/IDictionary.h"
#include "interfaces/ITextChecker.h"

class TextChecker : public ITextChecker
{
public:
    CheckerResult checkText(
            std::unique_ptr<IReader> reader,
            std::shared_ptr<IDictionary> dictionary,
            std::unique_ptr<std::ofstream> outputStream) final;
};

#endif //TEXTVERIFICATION_TEXTCHECKER_H
