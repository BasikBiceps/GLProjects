#ifndef TEXTVERIFICATION_SPECHASHTABLE_H
#define TEXTVERIFICATION_SPECHASHTABLE_H

#include <vector>
#include <string>

class SpecHashTable
{
public:
    explicit SpecHashTable(const std::size_t& size);
    SpecHashTable();

    void addElement(const std::string& element);
    bool isPresent(const std::string& element) const;

private:
    const std::size_t m_k_standartSize = 200000;
    std::size_t m_size;
    std::vector<std::vector<std::string>> m_table;
};

#endif //TEXTVERIFICATION_SPECHASHTABLE_H
