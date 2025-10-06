#include "BinarySearchTree.hpp"

template <typename T>
BinarySearchTree<T>::BinarySearchTree() : root{}, size{0} {}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
    clear();
}

template <typename T>
void BinarySearchTree<T>::insert(const_reference val) 
{
    root = dfs_insert(root, val);
    ++size;
}

template <typename T>
Node<T> *BinarySearchTree<T>::dfs_insert(Node<T>* node, const_reference val)
{
    if(!node) return new Node<T>(val);

    if(node->data > val) {
        node->left = dfs_insert(node->left, val);        
    }
    else {
        node->right = dfs_insert(node->right, val);
    }
    
    return node;
}

template <typename T>
bool BinarySearchTree<T>::search(const_reference value)
{
    return dfs_search(root, value);
}

template <typename T>
bool BinarySearchTree<T>::dfs_search(Node<T> *node, const_reference value)
{
    if(!node) return false;

    if(value > node->data) {
        return dfs_search(node->right, value);
    }
    else if (value < node->data) {
        return dfs_search(node->left, value);
    }
    else return true;
}

template <typename T>
typename BinarySearchTree<T>::size_type BinarySearchTree<T>::getHight()
{
    return dfs_Hight(root);
}

template <typename T>
typename BinarySearchTree<T>::size_type BinarySearchTree<T>::dfs_Hight(Node<T> *node)
{
    if(!node) return 0;

    size_t left = dfs_Hight(node->left);
    size_t right = dfs_Hight(node->right);

    return std::max(left, right) + 1;
}


template <typename T>
Node<T>* BinarySearchTree<T>::getMin()
{
    if(!root) return nullptr;

    Node<T>* tmp = root;
    while(!tmp->left) {
        tmp = tmp->left;
    }
    return tmp;
}

template <typename T>
Node<T>* BinarySearchTree<T>::getMax()
{
    if(!root) return nullptr;

    Node<T>* tmp = root;
    while(!tmp->right) {
        tmp = tmp->next;
    }
    return tmp;
}


template <typename T>
void BinarySearchTree<T>::print() const
{
    dfs_print(root);
    std::cout << std::endl;
}

template <typename T>
void BinarySearchTree<T>::dfs_print(Node<T> *node) const
{
    if(!node) return;

    dfs_print(node->left);
    std::cout << node->data << " ";
    dfs_print(node->right); 
}

template <typename T>
void BinarySearchTree<T>::clear()
{
    dfs_clear(root);
    root = nullptr;
    size = 0;
}

template <typename T>
void BinarySearchTree<T>::dfs_clear(Node<T>* node)
{
    if(!node) return;

    dfs_clear(node->left);
    dfs_clear(node->right);

    delete node;
}
