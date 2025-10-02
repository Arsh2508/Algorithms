#ifndef DLL_HPP
#define DLL_HPP

#include <initializer_list>

template <typename T>
struct Node {
    Node() : data{}, next{nullptr}, prev{nullptr} {}
    Node(const T& value) : data{value}, next{nullptr}, prev{nullptr} {}

    T data;
    Node<T>* next;
    Node<T>* prev;
};

template <typename T>
class List {
public:
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using size_type = size_t;
    using pointer = T*;
    using const_pointer = const T*;

    List();

    List(const List& other);
    List(List&& other);
    List(std::initializer_list<T> init);
    ~List();

    void push_back(const_reference value);
    void push_back(value_type&& value);
    void push_front(const_reference value);
    void push_front(value_type&& value);

    void pop_back();
    void pop_front();

    void insert(size_type pos, const_reference value);
    void erase(size_type pos);

    pointer find(const_reference value);

private:
    Node<T>* head;
    Node<T>* tail;
    size_type size;
};

#include "DLL.cpp"
#endif