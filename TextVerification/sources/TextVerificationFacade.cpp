#include <memory>
#include <iostream>
#include <filesystem>

#include "Helpers/FileSystemHelper.h"
#include "Readers/IReader.h"
#include "Readers/FileReader.h"
#include "Dictionaries/DictionaryFactory.h"
#include "Checkers/ITextChecker.h"
#include "Readers/PunctuationFilterFileReader.h"
#include "TextVerificationFacade.h"
#include "Checkers/TextChecker.h"
#include "Helpers/StringHelper.h"

void TextVerificationFacade::checkText(
        const std::string &dictionaryFilePath,
        const std::string &directoryWithTextsPath,
        const Dictionaries &dictionaryType,
        std::ostream &os)
{
    FileSystemHelper::createDirectoryIfNotExist(directoryWithTextsPath, "IncorrectWordsInTexts");

    std::unique_ptr<IReader> dictionaryReader = std::make_unique<FileReader>(dictionaryFilePath);
    std::unique_ptr<IDictionaryFactory> dictionaryFactory = std::make_unique<DictionaryFactory>();
    std::chrono::duration<double, std::milli> fillDictionaryDuration{};
    auto dictionary = dictionaryFactory->createAndFillDictionary(
            std::move(dictionaryReader),
            dictionaryType,
            fillDictionaryDuration);

    std::unique_ptr<ITextChecker> textChecker = std::make_unique<TextChecker>();
    CheckerResult checkerResult;

    for (const auto file : std::filesystem::directory_iterator(directoryWithTextsPath))
    {
        if (StringHelper::endsWith(file.path().string(), ".txt"))
        {
            std::string outputFileName =
                    directoryWithTextsPath +
                    "IncorrectWordsInTexts/" +
                    StringHelper::baseName(StringHelper::removeExtension(file.path().string())) +
                    "Incorrect.txt";

            auto outputFile = std::make_unique<std::ofstream>(outputFileName);

            if (!outputFile->is_open())
            {
                throw std::runtime_error("Failed to open output file!");
            }

            auto test = std::make_unique<PunctuationFilterFileReader>(file.path());
            checkerResult += textChecker->checkText(
                    std::move(test),
                    *dictionary,
                    std::move(outputFile));
        }
    }

    os << "All words checked: " << checkerResult.allWordsCounter << std::endl;
    os << "All incorrect words: " << checkerResult.incorrectWordsCounter << std::endl;
    os << "Spent time for check text: " << checkerResult.checkAllTextTime.count() << std::endl;
    os << "Spent time for fill dictionary: " << fillDictionaryDuration.count() << std::endl;
}