#include <algorithm>

#include "PunctuationFilterFileReader.h"

PunctuationFilterFileReader::PunctuationFilterFileReader(const std::string &filePath) :
    m_filePath(filePath),
    m_inputStream(std::make_unique<std::ifstream>(filePath, std::ifstream::in)) {}

std::string PunctuationFilterFileReader::readNext() {
    if (m_inputStream->is_open())
    {
        std::string result;
        *m_inputStream >> result;

        for (const auto c : result)
        {
            if (ispunct(c) && c != '`')
            {
                result.erase(std::find(result.begin(), result.end(), c));
            }
        }

        return result;
    }
    else
    {
        throw std::runtime_error("File stream is closed!");
    }
}
