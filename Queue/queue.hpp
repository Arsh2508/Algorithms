#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <deque>

template <typename T, typename Cont = std::deque<T>>
class Queue {
public:
    using value_type = T;
    using container_type = Cont;
    using reference = T&;
    using const_reference = const T&;
    using size_type = typename Cont::size_type;

    Queue() = default;

    Queue(const container_type& cont);
    Queue(container_type&& cont);

    void push(const_reference val);
    void push(value_type&& val);
    void pop();

    reference front();
    const_reference front() const;
    reference back();
    const_reference back() const;

    bool empty() const;
    size_type size() const;

private:
    Cont data;
};

#include "queue.cpp"
#endif