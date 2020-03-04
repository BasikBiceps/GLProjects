#ifndef TEXTVERIFICATION_SPECIALIZEDSTRINGBINARYSEARCHTREE_H
#define TEXTVERIFICATION_SPECIALIZEDSTRINGBINARYSEARCHTREE_H

#include <string>
#include <memory>

class SpecializedStringBinarySearchTree
{
public:
    SpecializedStringBinarySearchTree();
    ~SpecializedStringBinarySearchTree();

    SpecializedStringBinarySearchTree(const SpecializedStringBinarySearchTree& other) = delete;
    SpecializedStringBinarySearchTree& operator = (const SpecializedStringBinarySearchTree& other)= delete;

    void addElement(const std::string& str);
    bool isPresent(const std::string& str) const;

private:
    struct Node
    {
        Node(const std::string& str)
        {
            this->str = str;
            this->head = nullptr;
            this->left = nullptr;
            this->right = nullptr;
        }

        Node* head;
        Node* left;
        Node* right;
        std::string str;
    };

    void deleteBranch(Node* head, Node* branch);

private:
    Node* m_head;
};

#endif //TEXTVERIFICATION_SPECIALIZEDSTRINGBINARYSEARCHTREE_H
