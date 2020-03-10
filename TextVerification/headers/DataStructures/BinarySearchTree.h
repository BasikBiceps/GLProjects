#ifndef TEXTVERIFICATION_BINARYSEARCHTREE_H
#define TEXTVERIFICATION_BINARYSEARCHTREE_H

#include <string>
#include <memory>

class BinarySearchTree
{
public:
    BinarySearchTree();

    BinarySearchTree(const BinarySearchTree& other) = delete;
    BinarySearchTree& operator = (const BinarySearchTree& other)= delete;

    void addElement(const std::string& str);
    bool isPresent(const std::string& str) const;

private:
    struct Node
    {
        Node(const std::string& str)
        {
            this->str = str;
            this->left = nullptr;
            this->right = nullptr;
        }

        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;
        std::string str;
    };

private:
    std::unique_ptr<Node> m_head;
};

#endif //TEXTVERIFICATION_BINARYSEARCHTREE_H
