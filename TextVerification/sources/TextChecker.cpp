#include <chrono>

#include "TextChecker.h"

CheckerResult TextChecker::checkText(
        std::unique_ptr<IReader> reader,
        std::shared_ptr<IDictionary> dictionary,
        std::unique_ptr<std::ofstream> outputStream)
{
    if (!outputStream->is_open())
    {
        throw std::runtime_error("Output stream is close!");
    }

    CheckerResult checkerResult;
    auto startCheck = std::chrono::high_resolution_clock::now();
    std::string word = reader->readNext();

    if (word == "")
    {
        return checkerResult;
    }

    while (word != "")
    {
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
