#include <filesystem>

#include "Helpers/FileSystemHelper.h"

void FileSystemHelper::createDirectoryIfNotExist(const std::string &parentDirPath, const std::string &dirName)
{
    auto newDirPath = parentDirPath + dirName;

    if (!std::filesystem::exists(newDirPath))
    {
        std::filesystem::create_directory(parentDirPath + dirName);
    }
}
