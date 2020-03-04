#ifndef BINARYSEARCHTREE_BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_BINARYSEARCHTREE_H

#include <memory>

template <class T>
struct TreeNode
{
    TreeNode() = default;
    TreeNode(const std::shared_ptr<TreeNode>& r, const std::shared_ptr<TreeNode>&l, const std::shared_ptr<T>& value)
            : right(r)
            , left(l)
            , value(value) {}

    std::shared_ptr<TreeNode> right;
    std::shared_ptr<TreeNode> left;
    std::shared_ptr<T> value;
};

template <class T>
class BinarySearchTree
{
public:
    BinarySearchTree();

    template<class B>
    void addItem(B&& item);
    template<class B>
    std::shared_ptr<T> findElement(B&& item);
    template<class B>
    bool isPresent(const B& item) const;

    std::size_t getSize();
    const std::shared_ptr<TreeNode<T>>& getHead();

    void printTree(std::ostream& out);

private:
    template<class B>
    void addItem(const std::shared_ptr<TreeNode<T>>& head, B&& item);
    template<class B>
    bool isPresent(const std::shared_ptr<TreeNode<T>>& node, const B& item) const;
    template<class B>
    std::shared_ptr<T> findElement(const std::shared_ptr<TreeNode<T>>& node, B&& item);

    void printSubTree(std::ostream& out, const std::shared_ptr<TreeNode<T>>& node);

private:
    std::shared_ptr<TreeNode<T>> m_head = nullptr;
    std::size_t m_size;
};

template  <class T>
BinarySearchTree<T>::BinarySearchTree() : m_size(0) {}

template  <class T>
template <class B>
void BinarySearchTree<T>::addItem(const std::shared_ptr<TreeNode<T>>& head, B&& item)
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
template<class B>
std::shared_ptr<T> BinarySearchTree<T>::findElement(B&& item)
{
    return isPresent(getHead(), std::forward<B>(item));
}

template <class T>
template<class B>
std::shared_ptr<T> BinarySearchTree<T>::findElement(const std::shared_ptr<TreeNode<T>>& node, B&& item)
{
    if (node != nullptr && *node->value == item)
    {
        return node->value;
    }
    if (*node->value <= item && node->left != nullptr)
    {
        isPresent(node->left, std::forward<T>(item));
    } else if (*node->value > item && node->right != nullptr)
    {
        isPresent(node->right, std::forward<T>(item));
    }

    return nullptr;
}

template<class T>
template<class B>
bool BinarySearchTree<T>::isPresent(const B& item) const
{
    return isPresent(m_head, item);
}

template<class T>
template<class B>
bool BinarySearchTree<T>::isPresent(const std::shared_ptr<TreeNode<T>>& node, const B& item) const
{
    if (node != nullptr && *node->value == item)
    {
        return true;
    }
    if (*node->value <= item && node->left != nullptr)
    {
        isPresent(node->left, item);
    } else if (*node->value > item && node->right != nullptr)
    {
        isPresent(node->right, item);
    }

    return false;
}

template  <class T>
void BinarySearchTree<T>::printTree(std::ostream& out)
{
    printSubTree(out, getHead());
}

template  <class T>
void BinarySearchTree<T>::printSubTree(std::ostream& out, const std::shared_ptr<TreeNode<T>>& node)
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
const std::shared_ptr<TreeNode<T>>& BinarySearchTree<T>::getHead()
{
    return m_head;
}

#endif //BINARYSEARCHTREE_BINARYSEARCHTREE_H