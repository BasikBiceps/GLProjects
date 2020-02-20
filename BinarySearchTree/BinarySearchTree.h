//
// Created by baxter on 20.02.20.
//

#ifndef BINARYSEARCHTREE_BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_BINARYSEARCHTREE_H

#include <memory>

template <class T>
struct TreeNode
{
    TreeNode() = default;
    TreeNode(std::shared_ptr<TreeNode> const& r, std::shared_ptr<TreeNode> const&l, std::shared_ptr<T>const& value)
            : right(r)
            , left(l)
            , value(value)
    {
    }

    std::shared_ptr<TreeNode> right;
    std::shared_ptr<TreeNode> left;
    std::shared_ptr<T> value;
};

template <class T>
class BinarySearchTree {
public:
    BinarySearchTree();

    template<typename B>
    void addItem(B&& item);

    template<typename B>
    std::shared_ptr<T> findElement(B&& item);

    std::size_t getSize();
    std::shared_ptr<TreeNode<T>> const& getHead();

    void printTree(std::ostream& out);

private:
    template<typename B>
    void addItem(std::shared_ptr<TreeNode<T>> const& head, B&& item);

    template<typename B>
    std::shared_ptr<T> findElement(std::shared_ptr<TreeNode<T>> const& node, B&& item);
    void printSubTree(std::ostream& out, std::shared_ptr<TreeNode<T>> const& node);

private:
    std::shared_ptr<TreeNode<T>> m_head = nullptr;
    std::size_t m_size;
};

template  <class T>
BinarySearchTree<T>::BinarySearchTree() : m_size(0) {}

template  <class T>
template <typename B>
void BinarySearchTree<T>::addItem(std::shared_ptr<TreeNode<T>> const& head, B&& item)
{
    if (head == nullptr)
    {
        m_head = std::make_shared<TreeNode<T>>(nullptr, nullptr, std::make_shared<T>(item));
        ++m_size;
    } else if (*head->value <= item)
    {
        if (head->right == nullptr)
        {
            head->right = std::make_shared<TreeNode<T>>(nullptr, nullptr, std::make_shared<T>(item));
            ++m_size;
        } else {
            addItem(head->right, std::forward<B>(item));
        }
    } else
    {
        if (head->left == nullptr)
        {
            head->left = std::make_shared<TreeNode<T>>(nullptr, nullptr, std::make_shared<T>(item));
            ++m_size;
        } else {
            addItem(head->left, std::forward<B>(item));
        }
    }
}

template <class T>
template <class B>
void BinarySearchTree<T>::addItem(B&& item)
{
    addItem(getHead(), std::forward<B>(item));
}

template <class T>
template<typename B>
std::shared_ptr<T> BinarySearchTree<T>::findElement(B&& item)
{
    return findElement(getHead(), std::forward<B>(item));
}

template <class T>
template<typename B>
std::shared_ptr<T> BinarySearchTree<T>::findElement(std::shared_ptr<TreeNode<T>> const& node, B&& item)
{
    if (*node->value == item)
    {
        return node->value;
    }
    if (*node->value <= item && node->left != nullptr)
    {
        findElement(node->left, std::forward<T>(item));
    } else if (*node->value > item && node->right != nullptr)
    {
        findElement(node->right, std::forward<T>(item));
    }

    return nullptr;
}

template  <class T>
void BinarySearchTree<T>::printTree(std::ostream& out)
{
    printSubTree(out, getHead());
}

template  <class T>
void BinarySearchTree<T>::printSubTree(std::ostream& out, std::shared_ptr<TreeNode<T>> const& node)
{
    if(node->left != nullptr)
    {
        printSubTree(out, node->left);
    }

    out << *node->value << '\n';

    if (node->right != nullptr) {
        printSubTree(out, node->right);
    }
}

template  <class T>
std::size_t BinarySearchTree<T>::getSize()
{
    return m_size;
}

template  <class T>
std::shared_ptr<TreeNode<T>> const& BinarySearchTree<T>::getHead()
{
    return m_head;
}

#endif //BINARYSEARCHTREE_BINARYSEARCHTREE_H