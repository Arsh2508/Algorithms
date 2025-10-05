#include "BinarySearchTree.hpp"
//#include <iostream>

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
}

template <typename T>
void BinarySearchTree<T>::dfs_clear(Node<T>* node)
{
    if(!node) return;

    dfs_clear(node->left);
    dfs_clear(node_right);

    delete node;
}
