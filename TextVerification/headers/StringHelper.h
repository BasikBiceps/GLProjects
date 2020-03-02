#ifndef TEXTVERIFICATION_STRINGHELPER_H
#define TEXTVERIFICATION_STRINGHELPER_H

#include <algorithm>
#include <string>
#include <locale>

class StringHelper
{
public:
    static bool endsWith(const std::string& str, const std::string& suffix);
    template<class T>
    static T removeExtension(T const & filename);
    template<class T>
    static T baseName(T const & path, T const & delims = "/\\");
    static void strToLower(std::string& s);
};

template<class T>
T StringHelper::removeExtension(T const & filename)
{
    typename T::size_type const p(filename.find_last_of('.'));
    return p > 0 && p != T::npos ? filename.substr(0, p) : filename;
}

template<class T>
T StringHelper::baseName(T const & path, T const & delims)
{
    return path.substr(path.find_last_of(delims) + 1);
}

#endif //TEXTVERIFICATION_STRINGHELPER_H
