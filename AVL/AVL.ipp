#include "AVL.hpp"
#include <cstddef>


template <typename T>
AVL<T>::AVL() 
    : root{nullptr}
    , size{0}  
{}

template <typename T>
AVL<T>::AVL(std::initializer_list<T> init) : AVL() {
    for(auto &it : init) {
        insert(it);
    }
}

template <typename T>
AVL<T>::~AVL()
{
    clear();
}

template <typename T>
void AVL<T>::insert(const_reference value)
{
    root = dfs_insert(root, value);
    ++size;
}

template <typename T>
Node<T>* AVL<T>::dfs_insert(Node<T> *node, const_reference value)
{
    if(!node) return new Node<T>(value);

    if(node->data > value) {
        node->left = dfs_insert(node->left, value);
    }
    else {
        node->right = dfs_insert(node->right, value);
    }

    int bf = balance_factor(node);
    
    if(bf < -1) {
        if(balance_factor(node->right) < 0) {
            return left_rotate(node);
        }
        else{
            node->right = right_rotate(node->right);
            return left_rotate(node);
        }
    }
    else if(bf > 1){
        if(balance_factor(node->left) > 0) {
            return right_rotate(node);
        }
        else {
            node->left = left_rotate(node->left);
            return right_rotate(node);
        }
    }
    else {
        return node;
    }
}

template <typename T>
void AVL<T>::remove(const_reference value)
{
    root = dfs_remove(root, value);
    --size;
}

template <typename T>
Node<T>* AVL<T>::dfs_remove(Node<T>* node, const_reference value) 
{
    if(!node) return nullptr;

    if(node->data > value) {
        node->left = dfs_remove(node->left, value);
    }
    else if(node->data < value) {
        node->right = dfs_remove(node->right, value);
    }
    else {
        if(node->left && node->right) {
            Node<T>* tmp = successor(node);
            std::swap(tmp->data, node->data);
            node->right = dfs_remove(node->right, value);
        }
        else if(node->left) {
            Node<T>* tmp = node->left;
            delete node;
            return tmp;
        }
        else if(node->right) {
            Node<T>* tmp = node->right;
            delete node;
            return tmp;
        }
        else {
            delete node;
            return nullptr;
        }
    }

    int bf = balance_factor(node);
    
    if(bf < -1) {
        if(balance_factor(node->right) <= 0) {
            return left_rotate(node);
        }
        else{
            node->right = right_rotate(node->right);
            return left_rotate(node);
        }
    }
    else if(bf > 1){
        if(balance_factor(node->left) >= 0) {
            return right_rotate(node);
        }
        else {
            node->left = left_rotate(node->left);
            return right_rotate(node);
        }
    }
    else {
        return node;
    }
}


template <typename T>
bool AVL<T>::search(const_reference value)
{
    return dfs_search(root, value);
}

template <typename T>
bool AVL<T>::dfs_search(Node<T> *node, const_reference value)
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
typename AVL<T>::size_type AVL<T>::getHight() 
{
    return dfsHight(root);
}

template <typename T>
Node<T> *AVL<T>::getMin() const
{
    Node<T>* temp = root;

    while(temp->left) {
        temp = temp->left;
    }
    return temp;
}

template <typename T>
Node<T> *AVL<T>::getMax() const
{
    Node<T>* temp = root;

    while(temp->right) {
        temp = temp->right;
    }
    return temp;
}

template <typename T>
Node<T> *AVL<T>::successor(Node<T> *node)
{
    if(!node) return nullptr;

    if(node->right) {
        Node<T>* tmp = node->right;
        while(tmp->left) {
            tmp = tmp->left;
        }
        return tmp;
    }

    Node<T>* tmp = root;
    Node<T>* res = nullptr;

    while(tmp && tmp != node) {
        if(tmp->data > node->data) {
            res = tmp;
            tmp = tmp->left;
        }
        else {
            tmp = tmp->right;
        }
    }
    return res;
}

template <typename T>
Node<T> *AVL<T>::predecessor(Node<T> *node)
{
    if(!node) return nullptr;

    if(node->left) {
        Node<T>* tmp = node->left;
        while(tmp->right) {
            tmp = tmp->right;
        }
        return tmp;
    }

    Node<T>* res = nullptr;
    Node<T>* tmp = root;

    while(tmp && tmp != node) {
        if(tmp->data < node->data) {
            res = tmp;
            tmp = tmp->right;
        }
        else {
            tmp = tmp->left;
        }
    }

    return res;
}

template <typename T>
typename AVL<T>::size_type AVL<T>::dfsHight(Node<T> *node) 
{
    if(!node) return 0;

    size_t left = dfsHight(node->left);
    size_t right = dfsHight(node->right);

    return std::max(left, right) + 1;
}

template <typename T>
Node<T>* AVL<T>::right_rotate(Node<T> *x)
{
    Node<T>* y = x->left;
    Node<T>* T2 = y->right;
    y->right = x;
    x->left = T2;

    return y;
}

template <typename T>
Node<T>* AVL<T>::left_rotate(Node<T> *x)
{
    Node<T>* y = x->right;
    Node<T>* T2 = y->left;
    y->left = x;
    x->right = T2;

    return y;
}

template <typename T>
int AVL<T>::balance_factor(Node<T> *node)
{
    return dfsHight(node->left) - dfsHight(node->right);
}

template <typename T>
typename AVL<T>::size_type AVL<T>::getSize() const noexcept
{
    return size;
}

template <typename T>
void AVL<T>::print() const noexcept
{
    dfs_print(root);
    std::cout << std::endl;
}

template <typename T>
void AVL<T>::dfs_print(Node<T> *node) const
{
    if(!node) return;

    dfs_print(node->left);
    dfs_print(node->right); 
    std::cout << node->data << " ";
}

template <typename T>
void AVL<T>::clear()
{
    dfs_clear(root);
    root = nullptr;
    size = 0;
}

template <typename T>
void AVL<T>::dfs_clear(Node<T> *node)
{
    if(!node) return;

    dfs_clear(node->left);
    dfs_clear(node->right);

    delete node;
}