#include "FileReader.h"

FileReader::FileReader(const std::string &filePath) :
    m_filePath(filePath),
    m_inputStream(std::make_unique<std::ifstream>(filePath, std::ifstream::in)) {}

std::string FileReader::readNext()
{
    if (m_inputStream->is_open())
    {
        std::string result;
        *m_inputStream >> result;

        return result;
    }
    else
    {
        throw std::runtime_error("File stream is closed!");
    }
}
