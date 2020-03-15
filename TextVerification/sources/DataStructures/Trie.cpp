#include "DataStructures/Trie.h"

Trie::Trie() : m_head(std::make_unique<TrieNode>()) {}

void Trie::addElement(std::string const &element)
{
    TrieNode* pNode = m_head.get();

    for (char i : element)
    {
        int index = i - 'a';

        if (i == '\'')
        {
            index = TrieNode::k_apostropheIndex;
        }

        if (!pNode->children[index])
        {
            pNode->children[index] = std::make_unique<TrieNode>();
        }

        pNode = pNode->children[index].get();
    }

    pNode->isEndOfWord = true;
}

bool Trie::isPresent(std::string const &element) const
{
    TrieNode* pNode = m_head.get();

    for (char i : element)
    {
        int index = i - 'a';

        if (i == '\'')
            index = TrieNode::k_apostropheIndex;

        if (index >= TrieNode::k_alphabetSize)
        {
            continue;
        }

        if (!pNode->children[index])
        {
            return false;
        }

        pNode = pNode->children[index].get();
    }

    return (pNode != nullptr && pNode->isEndOfWord);
}