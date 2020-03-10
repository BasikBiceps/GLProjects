#include <algorithm>

#include "DataStructures/SpecHashTable.h"

SpecHashTable::SpecHashTable(const std::size_t& size) : m_size(size)
{
    m_table.resize(size);
}

SpecHashTable::SpecHashTable() : m_size(m_k_standartSize)
{
    m_table.resize(m_k_standartSize);
}

void SpecHashTable::addElement(const std::string &element)
{
    auto index = std::hash<std::string>()(element) % m_size;

    m_table[index].push_back(element);
}

bool SpecHashTable::isPresent(const std::string &element) const
{
    auto index = std::hash<std::string>()(element) % m_size;
    auto bucket = m_table[index];

    return std::find(bucket.begin(), bucket.end(), element) != bucket.end();
}
