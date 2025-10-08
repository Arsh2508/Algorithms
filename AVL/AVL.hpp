#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>
#include <cstddef>
#include <initializer_list>
#include "Node.hpp"

template <typename T>
class  AVL{
public:
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using size_type = size_t;

    AVL();
    AVL(std::initializer_list<T> init);
    
    ~AVL();

    void insert(const_reference value);
    void remove(const_reference value);
    bool search(const_reference value);
    size_type getHight();
    Node<T>* getMin() const;
    Node<T>* getMax() const;
    Node<T>* successor(Node<T>* node);
    Node<T>* predecessor(Node<T>* node);

    size_type getSize() const noexcept;
    void print() const noexcept;
    void clear();

private:
    Node<T>* dfs_insert(Node<T>* node, const_reference value);
    Node<T>* dfs_remove(Node<T>* node, const_reference value);
    bool dfs_search(Node<T>* node, const_reference value);
    size_type dfsHight(Node<T>* node);
    Node<T>* left_rotate(Node<T>* node);
    Node<T>* right_rotate(Node<T>* node);
    int balance_factor(Node<T>* node);

    void balance(Node<T>* node);

    void dfs_print(Node<T>* node) const;
    void dfs_clear(Node<T>* node);


    Node<T>* root;
    size_type size;

};

#include "AVL.ipp"
#endif