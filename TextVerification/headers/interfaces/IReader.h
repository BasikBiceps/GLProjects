#ifndef TEXTVERIFICATION_IREADER_H
#define TEXTVERIFICATION_IREADER_H

#include <string>

class IReader
{
public:
    IReader() = default;
    virtual ~IReader() = default;

    IReader(const IReader& another) = delete;
    IReader& operator = (const IReader& another) = delete;

    virtual std::string readNext() = 0;
};

#endif //TEXTVERIFICATION_IREADER_H
