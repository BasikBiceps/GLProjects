#include <chrono>

#include "TextChecker.h"

CheckerResult TextChecker::checkText(
        std::unique_ptr<IReader> reader,
        std::shared_ptr<IDictionary> dictionary,
        std::unique_ptr<std::ofstream> outputStream)
{
    if (!outputStream->is_open())
    {
        throw std::runtime_error("Failed to open output file in TextChecker!");
    }

    CheckerResult checkerResult;
    auto startCheck = std::chrono::high_resolution_clock::now();
    std::string word = reader->readNext();

    if (word == "EOF")
    {
        return checkerResult;
    }

    while (word != "EOF") {
        if (word.length() == 0)
        {
            word = reader->readNext();
            continue;
        }

        auto isPresentInDictionary = dictionary->isPresent(word);

        if (!isPresentInDictionary)
        {
            ++checkerResult.incorrectWordsCounter;
            *outputStream << word + "\n";
        }

        ++checkerResult.allWordsCounter;
        word = reader->readNext();
    }

    auto stopCheck = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stopCheck - startCheck);

    checkerResult.checkAllTextTime = duration;

    return checkerResult;
}
