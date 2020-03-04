#include <filesystem>
#include <iostream>
#include <memory>

#include "interfaces/IDictionaryFactory.h"
#include "TextVerificationFacade.h"

int main()
{
    std::cout << "SpecializedHashTableDictionary:" << std::endl;
    TextVerificationFacade::checkText(
            std::filesystem::current_path().parent_path().string() + "/dictionaries/dictionary",
            std::filesystem::current_path().parent_path().string() + "/texts/",
            Dictionaries::SpecializedHashTableDictionary,
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

    std::cout << "SpecializedBinarySearchTreeDictionary:" << std::endl;
    TextVerificationFacade::checkText(
            std::filesystem::current_path().parent_path().string() + "/dictionaries/dictionary",
            std::filesystem::current_path().parent_path().string() + "/texts/",
            Dictionaries::SpecializedBinarySearchTreeDictionary,
            std::cout);

    return 0;
}
