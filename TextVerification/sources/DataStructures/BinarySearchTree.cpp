#include "DataStructures/BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() : m_head(nullptr) {}

void BinarySearchTree::addElement(const std::string &str)
{
    if (m_head == nullptr)
    {
        m_head = std::make_unique<Node>(str);
        return;
    }

    auto pNode = m_head.get();

    while (pNode)
    {
        if (str > pNode->str)
        {
            if (pNode->right == nullptr)
            {
                pNode->right = std::make_unique<Node>(str);
                pNode = nullptr;
            }
            else
            {
                pNode = pNode->right.get();
            }
        }
        else
        {
            if (pNode->left == nullptr)
            {
                pNode->left = std::make_unique<Node>(str);
                pNode = nullptr;
            }
            else
            {
                pNode = pNode->left.get();
            }
        }
    }
}

bool BinarySearchTree::isPresent(const std::string &str) const
{
    if (m_head == nullptr)
    {
        return false;
    }

    auto pNode = m_head.get();
    bool result = false;

    while (pNode)
    {
        if (str > pNode->str)
        {
            if (pNode->right == nullptr)
            {
                result = false;
                pNode = nullptr;
            }
            else
            {
                pNode = pNode->right.get();
            }
        }
        else if (str < pNode->str)
        {
            if (pNode->left == nullptr)
            {
                result = false;
                pNode = nullptr;
            }
            else
            {
                pNode = pNode->left.get();
            }
        }
        else
        {
            result = true;
            pNode = nullptr;
        }
    }

    return result;
}