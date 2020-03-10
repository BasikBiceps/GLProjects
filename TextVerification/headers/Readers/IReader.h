#ifndef TEXTVERIFICATION_IREADER_H
#define TEXTVERIFICATION_IREADER_H

#include <string>

class IReader
{
public:
    IReader() = default;
    virtual ~IReader() = default;

    virtual std::string readNext() = 0;
};

#endif //TEXTVERIFICATION_IREADER_H
