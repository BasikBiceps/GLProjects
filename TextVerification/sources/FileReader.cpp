#include "FileReader.h"

FileReader::FileReader(const std::string &filePath) :
    m_filePath(filePath),
    m_inputStream(std::make_unique<std::ifstream>(filePath, std::ifstream::in)),
    m_stringstream(std::make_unique<std::stringstream>()) {}

std::string FileReader::readNext()
{
    if (m_inputStream->is_open())
    {
        std::string word;

        *m_stringstream >> word;

        if (word.size() == 0)
        {
            m_stringstream->clear();

            std::string tempStr;
            std::getline(*m_inputStream, tempStr);

            if(!*m_inputStream)
            {
                return "EOF";
            }

            *m_stringstream << tempStr;
            *m_stringstream >> word;
        }

        return word;
    }
    else
    {
        throw std::runtime_error("Failed to open input file in FileReader!");
    }
}
