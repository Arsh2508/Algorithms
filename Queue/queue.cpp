#include "queue.hpp"

template <typename T, typename Cont>
Queue<T, Cont>::Queue(const container_type& cont) : data{cont} {}

template <typename T, typename Cont>
Queue<T, Cont>::Queue(container_type&& cont) : data{std::move(cont)} {}

template <typename T, typename Cont>
void Queue<T, Cont>::push(const_reference val) 
{
    data.push_back(val);
}

template <typename T, typename Cont>
void Queue<T, Cont>::push(value_type&& val) 
{
    data.push_back(std::move(val));
}

template <typename T, typename Cont>
void Queue<T, Cont>::pop() 
{
    data.pop_front();
}

template <typename T, typename Cont>
typename Queue<T, Cont>::const_reference Queue<T, Cont>::front() const 
{
    return data.front();
}

template <typename T, typename Cont>
typename Queue<T, Cont>::reference Queue<T, Cont>::front() 
{
    return data.front();
}

template <typename T, typename Cont>
typename Queue<T, Cont>::const_reference Queue<T, Cont>::back() const 
{
    return data.back();
}

template <typename T, typename Cont>
typename Queue<T, Cont>::reference Queue<T, Cont>::back() 
{
    return data.back();
}

template <typename T, typename Cont>
bool Queue<T, Cont>::empty() const 
{
    return data.empty();
}

template <typename T, typename Cont>
typename Queue<T, Cont>::size_type Queue<T, Cont>::size() const 
{
    return data.size();
}