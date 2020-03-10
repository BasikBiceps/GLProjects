#include <algorithm>
#include <Helpers/StringHelper.h>

#include "Readers/PunctuationFilterFileReader.h"

PunctuationFilterFileReader::PunctuationFilterFileReader(const std::string &filePath) :
    m_filePath(filePath),
    m_inputStream(std::make_unique<std::ifstream>(filePath, std::ifstream::in)) {}

std::string PunctuationFilterFileReader::readNext()
{
    if (m_inputStream->is_open())
    {
        std::string word;

        m_stringstream >> word;

        if (word.length() == 0)
        {
            m_stringstream.clear();

            std::string tempStr;

            while (tempStr == "" && *m_inputStream)
            {
                std::getline(*m_inputStream, tempStr);
            }

            if(!*m_inputStream)
            {
                return "EOF";
            }

            m_stringstream << tempStr;
            m_stringstream >> word;
        }

        StringHelper::strToLower(word);

        for (auto it = word.begin(); it != word.end();)
        {
            if (word.length() == 0)
            {
                return "";
            }

            if (!isRightSymbol(*it))
            {
                auto temp = it;
                word.erase(temp);
                it = word.begin();
            }
            else
            {
                ++it;
            }
        }

        return word;
    }
    else
    {
        throw std::runtime_error("Failed to open input file in PunctuationFileReader!");
    }
}

bool PunctuationFilterFileReader::isRightSymbol(char symbol)
{
    return std::isalpha(symbol)  || symbol == '`';
}


