#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

template <typename T>
struct Node {
    Node() : data{}, left{nullptr}, right{nullptr} {}
    Node(const T& val) : data{val}, left{nullptr}, right{nullptr} {} 

    T data;
    Node<T>* left;
    Node<T>* right;
};

template <typename T>
class BinarySearchTree {
public:
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using size_type = size_t;

    BinarySearchTree();
    ~BinarySearchTree();

    void insert(const_reference value);
    void remove(const_reference value);
    bool search(const_reference value);
    size_type getHight();
    Node<T>* getMin();
    Node<T>* getMax();
    Node<T>* successor(Node<T>* node);
    Node<T>* predecessor(Node<T>* node);
    
    void print() const;
    void clear();
    
    private:
    Node<T>* root;
    size_type size;
    
    Node<T>* dfs_insert(Node<T>* node, const_reference value);
    Node<T>* dfs_remove(Node<T>* node, const_reference value);
    void dfs_print(Node<T>* node) const;
    void dfs_clear(Node<T>* node);
    bool dfs_search(Node<T>* node, const_reference value);
    size_type dfs_Hight(Node<T>* node);
};

#include "BinarySearchTree.ipp"
#endif

