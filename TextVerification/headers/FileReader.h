#ifndef TEXTVERIFICATION_FILEREADER_H
#define TEXTVERIFICATION_FILEREADER_H

#include <string>
#include <memory>
#include <fstream>

#include "interfaces/IReader.h"

class FileReader : public IReader
{
public:
    explicit FileReader(const std::string& filePath);

    std::string readNext() override;

private:
    std::unique_ptr<std::ifstream> m_inputStream;
    std::string m_filePath;
};

#endif //TEXTVERIFICATION_FILEREADER_H

