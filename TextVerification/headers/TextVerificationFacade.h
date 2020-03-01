//
// Created by baxter on 01.03.20.
//

#ifndef TEXTVERIFICATION_TEXTVERIFICATIONFACADE_H
#define TEXTVERIFICATION_TEXTVERIFICATIONFACADE_H

#include <string>

class TextVerificationFacade {
public:
    void TextCheckWithVectorDictionary(
            const std::string& dictionaryFilePath,
            const std::string& directoryWithTextsPath);

    void TextCheckWithHashTableDictionary(
            const std::string& dictionaryFilePath,
            const std::string& directoryWithTextsPath);

    void TextCheckWith(
            const std::string& dictionaryFilePath,
            const std::string& directoryWithTextsPath);

private:
    void createDirectoryIfNotExist(const std::string& parentDirPath, const std::string& dirName);
    bool ends_with(const std::string& str, const std::string& suffix);
    template<class T>
    T remove_extension(T const & filename);
    template<class T>
    T base_name(T const & path, T const & delims = "/\\");
};

template<class T>
T TextVerificationFacade::remove_extension(T const & filename)
{
    typename T::size_type const p(filename.find_last_of('.'));
    return p > 0 && p != T::npos ? filename.substr(0, p) : filename;
}

template<class T>
T TextVerificationFacade::base_name(T const & path, T const & delims)
{
    return path.substr(path.find_last_of(delims) + 1);
}

#endif //TEXTVERIFICATION_TEXTVERIFICATIONFACADE_H
