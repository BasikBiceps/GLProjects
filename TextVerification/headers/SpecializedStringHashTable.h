#ifndef TEXTVERIFICATION_SPECIALIZEDSTRINGHASHTABLE_H
#define TEXTVERIFICATION_SPECIALIZEDSTRINGHASHTABLE_H

#include <vector>
#include <string>

class SpecializedStringHashTable
{
public:
    explicit SpecializedStringHashTable(const std::size_t& size);
    SpecializedStringHashTable();

    void addElement(const std::string& element);
    bool isPresent(const std::string& element) const;

private:
    const std::size_t m_k_standartSize = 200000;
    std::size_t m_size;
    std::vector<std::vector<std::string>> m_table;
};

#endif //TEXTVERIFICATION_SPECIALIZEDSTRINGHASHTABLE_H
