#include <filesystem>

#include "TextVerificationFacade.h"

int main() {
    TextVerificationFacade textVerificationFacade;
    textVerificationFacade.TextCheckWithVectorDictionary(
            std::filesystem::current_path().parent_path().string() + "/dictionaries/dictionary",
            std::filesystem::current_path().parent_path().string() + "/texts/");

    return 0;
}
