#include <algorithm>

#include "SpecializedStringHashTable.h"

SpecializedStringHashTable::SpecializedStringHashTable(const std::size_t& size) : m_size(size)
{
    m_table.resize(size);
}

SpecializedStringHashTable::SpecializedStringHashTable() : m_size(m_k_standartSize)
{
    m_table.resize(m_k_standartSize);
}

void SpecializedStringHashTable::addElement(const std::string &element)
{
    auto index = std::hash<std::string>()(element) % m_size;

    m_table[index].push_back(element);
}

bool SpecializedStringHashTable::isPresent(const std::string &element) const
{
    auto index = std::hash<std::string>()(element) % m_size;
    auto bucket = m_table[index];

    return std::find(bucket.begin(), bucket.end(), element) != bucket.end();
}
