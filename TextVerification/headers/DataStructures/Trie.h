#ifndef TESTTRIE_TRIE_H
#define TESTTRIE_TRIE_H

#include <vector>
#include <memory>

class Trie
{
public:
    Trie();

    void addElement(std::string const& element);
    bool isPresent(std::string const& element) const;

private:
    struct TrieNode
    {
        const static std::size_t k_alphabetSize = 27;
        const static std::size_t k_apostropheIndex = 26;

        TrieNode() : children(k_alphabetSize), isEndOfWord(false) {}

        std::vector<std::unique_ptr<TrieNode>> children;
        bool isEndOfWord;
    };

private:
    std::unique_ptr<TrieNode> m_head;
};

#endif //TESTTRIE_TRIE_H
