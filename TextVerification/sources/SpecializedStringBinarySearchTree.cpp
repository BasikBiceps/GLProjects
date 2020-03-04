#include "SpecializedStringBinarySearchTree.h"

SpecializedStringBinarySearchTree::SpecializedStringBinarySearchTree() : m_head(nullptr) {}

void SpecializedStringBinarySearchTree::addElement(const std::string &str)
{
    if (m_head == nullptr)
    {
        m_head = new Node(str);
        return;
    }

    Node* pNode = m_head;

    while (pNode)
    {
        if (str > pNode->str)
        {
            if (pNode->right == nullptr)
            {
                pNode->right = new Node(str);
                pNode->right->head = pNode;
                pNode = nullptr;
            }
            else
            {
                pNode = pNode->right;
            }
        }
        else
        {
            if (pNode->left == nullptr)
            {
                pNode->left = new Node(str);
                pNode->left->head = pNode;
                pNode = nullptr;
            }
            else
            {
                pNode = pNode->left;
            }
        }
    }
}

bool SpecializedStringBinarySearchTree::isPresent(const std::string &str) const
{
    if (m_head == nullptr)
    {
        return false;
    }

    Node* pNode = m_head;
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
                pNode = pNode->right;
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
                pNode = pNode->left;
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

SpecializedStringBinarySearchTree::~SpecializedStringBinarySearchTree()
{
    if (m_head == nullptr)
    {
        return;
    }

    if (m_head->left != nullptr)
    {
        deleteBranch(m_head, m_head->left);
    }

    if (m_head->right != nullptr)
    {
        deleteBranch(m_head, m_head->right);
    }

    delete m_head;
    m_head = nullptr;
}

void SpecializedStringBinarySearchTree::deleteBranch(SpecializedStringBinarySearchTree::Node *head,
                                                     SpecializedStringBinarySearchTree::Node *branch)
{
    while (head != nullptr)
    {
        if (branch->left != nullptr)
        {
            head = branch;
            branch = branch->left;
        }
        else if (branch->right != nullptr)
        {
            head = branch;
            branch = branch->right;
        }
        else
        {
            if (head->left == branch)
            {
                head->left = nullptr;
            }
            else if (head->right == branch)
            {
                head->right = nullptr;
            }

            delete branch;
            branch = head;
            head = head->head;
        }
    }
}