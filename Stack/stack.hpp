#ifndef STACK_HPP
#define STACK_HPP

#include <deque>

template <typename T, typename Cont = std::deque<T>>
class Stack {
public:
    using value_type = T;
    using container_type = Cont;
    using reference = T&;
    using const_reference = const T&;
    using size_type = typename Cont::size_type;

    Stack() = default;

    explicit Stack(const container_type& cont);
    explicit Stack(container_type && cont);

    void push(const_reference val);
    void push(value_type&& val);
    void pop();
    size_type size() const;
    bool empty() const; 

    reference top();
    const_reference top() const;

private:
    Cont data;
};

#include "stack.cpp"
#endif