#include "DLL.hpp"
#include <stdexcept>

template <typename T>
List<T>::List() : head{nullptr}, tail{nullptr}, size{0} {}

    template <typename T>
    List<T>::List(const List &other) : List()
    {
        Node<T>* tmp = other.head;

        while(tmp) {
            push_back(tmp->data);
            tmp = tmp->next;
        }
    }

template <typename T>
List<T>::List(List &&other) : head{other.head}, tail{other.tail}, size{other.size}
{
    other.head = nullptr;
    other.tail = nullptr;
    other.size = 0;
}

template <typename T>
List<T>::List(std::initializer_list<T> init) : List()
{
    for(auto & val : init) {
        push_back(val);
    }
}

template <typename T>
List<T>::~List()
{
    Node<T>* tmp = head;
    while(tmp) {
        tmp->data.~T();
        Node<T>* del = tmp;
        tmp = tmp->next;
        ::operator delete(del);
    }
}

template <typename T>
void List<T>::push_back(const_reference value)
{
    Node<T>* new_node = static_cast<Node<T>*>(::operator new(sizeof(Node<T>)));
    
    try {
        new (&new_node->data) T(value);
        new_node->next = nullptr;
        new_node->prev = tail;
    }
    catch(...) {
        ::operator delete(new_node);
        throw;
    }

    if(!tail) {
        head = tail = new_node;
    }
    else {
        tail->next = new_node;
        tail = new_node;
    }
    ++size;
}

template <typename T>
void List<T>::push_back(value_type &&value)
{
    Node<T>* new_node = static_cast<Node<T>*>(::operator new(sizeof(Node<T>)));
    
    try {
        new (&new_node->data) T(std::move(value));
        new_node->next = nullptr;
        new_node->prev = tail;
    }
    catch(...) {
        ::operator delete(new_node);
        throw;
    }

    if(!tail) {
        head = tail = new_node;
    }
    else {
        tail->next = new_node;
        tail = new_node;
    }
    ++size;
}

template <typename T>
void List<T>::push_front(const_reference value)
{
    Node<T>* new_node = static_cast<Node<T>*>(::operator new(sizeof(Node<T>)));

    try {
        new (&new_node->data) T(value);
        new_node->prev = nullptr;
        new_node->next = head;
    }
    catch(...) {
        ::operator delete(new_node);
        throw;
    }

    if(!head) {
        head = tail = new_node;
    }
    else {
        head->prev = new_node;
        head = new_node;
    }
    ++size;
}

template <typename T>
void List<T>::push_front(value_type&& value)
{
    Node<T>* new_node = static_cast<Node<T>*>(::operator new(sizeof(Node<T>)));

    try {
        new (&new_node->data) T(std::move(value));
        new_node->prev = nullptr;
        new_node->next = head;
    }
    catch(...) {
        ::operator delete(new_node);
        throw;
    }

    if(!head) {
        head = tail = new_node;
    }
    else {
        head->prev = new_node;
        head = new_node;
    }
    ++size;
}

template <typename T>
void List<T>::pop_back()
{
    if(!tail) {
        throw std::out_of_range("List is empty");
    }

    Node<T>* tmp = tail;
    
    if(tail == head) {
        head = tail = nullptr;
    }
    else {
        tail = tail->prev;
        tail->next = nullptr;
    }

    tmp->data.~T();
    ::operator delete(tmp);
}

template <typename T>
void List<T>::pop_front()
{
    if(!head) {
        throw std::out_of_range("List is empty!");
    }

    Node<T>* tmp = head;

    if(head == tail) {
        head = tail = nullptr;
    }
    else {
        head = head->next;
        head->prev = nullptr;
    }

    tmp->data.~T();
    ::operator delete(tmp);
}


