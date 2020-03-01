#include <memory>
#include <iostream>

#include "filesystem"
#include "interfaces/IReader.h"
#include "FileReader.h"
#include "DictionaryFactory.h"
#include "interfaces/ITextChecker.h"
#include "PunctuationFilterFileReader.h"
#include "TextVerificationFacade.h"
#include "TextChecker.h"

void TextVerificationFacade::TextCheckWithVectorDictionary(const std::string &dictionaryFilePath,
                                                           const std::string &directoryWithTextsPath)
{
    createDirectoryIfNotExist(directoryWithTextsPath, "IncorrectWordsInTexts");

    std::unique_ptr<IReader> dictionaryReader = std::make_unique<FileReader>(dictionaryFilePath);
    std::unique_ptr<IDictionaryFactory> dictionaryFactory = std::make_unique<DictionaryFactory>();
    std::chrono::duration<double, std::milli> fillDictionaryDuration;
    auto dictionary =  dictionaryFactory->createDictionary(
            std::move(dictionaryReader),
            Dictionaries::VectorDictionary,
            fillDictionaryDuration);

    std::unique_ptr<ITextChecker> textChecker = std::make_unique<TextChecker>();
    CheckerResult checkerResult;

    for (const auto file : std::filesystem::directory_iterator(directoryWithTextsPath))
    {
        if (ends_with(file.path().string(), ".txt"))
        {
            std::string outputFileName =
                    directoryWithTextsPath +
                    "IncorrectWordsInTexts/" +
                    base_name(remove_extension(file.path().string())) +
                    "Incorrect.txt";

            auto outputFile = std::make_unique<std::ofstream>(outputFileName);

            if (!outputFile->is_open())
            {
                throw std::runtime_error("Failed to open output file!");
            }

            checkerResult += textChecker->checkText(
                    std::make_unique<PunctuationFilterFileReader>(file.path()),
                    dictionary,
                    std::move(outputFile));
        }
    }

        std::cout << "All wor<ds checked: " << checkerResult.allWordsCounter << std::endl;
        std::cout << "All incorrect words: " << checkerResult.incorrectWordsCounter << std::endl;
        std::cout << "Spent time for check text: " << checkerResult.checkAllTextTime.count() << std::endl;
        std::cout << "Spent time for fill dictionary: " << fillDictionaryDuration.count() << std::endl;
}

bool TextVerificationFacade::ends_with(const std::string &str, const std::string &suffix)
{
    if (str.size() < suffix.size())
    {
        return false;
    }

    return str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

void TextVerificationFacade::createDirectoryIfNotExist(const std::string &parentDirPath, const std::string& dirName) {
    auto newDirPath = parentDirPath + dirName;
    if (!std::filesystem::exists(newDirPath))
    {
        std::filesystem::create_directory(parentDirPath + dirName);
    }
}
