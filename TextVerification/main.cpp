#include <filesystem>
#include <iostream>

#include "Dictionaries/IDictionaryFactory.h"
#include "TextVerificationFacade.h"

int main()
{
    std::cout << "TrieDictionary:" << std::endl;
    TextVerificationFacade::checkText(
            std::filesystem::current_path().parent_path().string() + "/dictionaries/dictionary",
            std::filesystem::current_path().parent_path().string() + "/texts/",
            Dictionaries::TrieDictionary,
            std::cout);

    std::cout << "SpecHashTableDictionary:" << std::endl;
    TextVerificationFacade::checkText(
            std::filesystem::current_path().parent_path().string() + "/dictionaries/dictionary",
            std::filesystem::current_path().parent_path().string() + "/texts/",
            Dictionaries::SpecHashTableDictionary,
            std::cout);

    std::cout << "HashTableDictionary:" << std::endl;
    TextVerificationFacade::checkText(
            std::filesystem::current_path().parent_path().string() + "/dictionaries/dictionary",
            std::filesystem::current_path().parent_path().string() + "/texts/",
            Dictionaries::HashTableDictionary,
            std::cout);

    std::cout << "VectorDictionary:" << std::endl;
    TextVerificationFacade::checkText(
            std::filesystem::current_path().parent_path().string() + "/dictionaries/dictionary",
            std::filesystem::current_path().parent_path().string() + "/texts/",
            Dictionaries::VectorDictionary,
            std::cout);

    std::cout << "BinarySearchTreeDictionary:" << std::endl;
    TextVerificationFacade::checkText(
            std::filesystem::current_path().parent_path().string() + "/dictionaries/dictionary",
            std::filesystem::current_path().parent_path().string() + "/texts/",
            Dictionaries::BinarySearchTreeDictionary,
            std::cout);

    return 0;
}
