#ifndef TEXTVERIFICATION_FILESYSTEMHELPER_H
#define TEXTVERIFICATION_FILESYSTEMHELPER_H

#include <string>

class FileSystemHelper
{
public:
    static void createDirectoryIfNotExist(const std::string& parentDirPath, const std::string& dirName);
};

#endif //TEXTVERIFICATION_FILESYSTEMHELPER_H
