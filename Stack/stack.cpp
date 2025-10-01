#include "stack.hpp"

template <typename T, typename Cont>
Stack<T, Cont>::Stack(const container_type &cont) : data{cont} {}

template <typename T, typename Cont>
Stack<T, Cont>::Stack(container_type &&cont) : data{std::move(cont)} {}

template <typename T, typename Cont>
void Stack<T, Cont>::pop()
{
    data.pop_back();
}

template <typename T, typename Cont>
void Stack<T, Cont>::push(const_reference val)
{
    data.push_back(val);
}

template <typename T, typename Cont>
void Stack<T, Cont>::push(value_type&& val)
{
    data.push_back(std::move(val));
}

template <typename T, typename Cont>
typename Stack<T, Cont>::const_reference Stack<T, Cont>::top() const
{
    return data.back();
}

template <typename T, typename Cont>
typename Stack<T, Cont>::reference Stack<T, Cont>::top()
{
    return data.back();
}

template <typename T, typename Cont>
bool Stack<T, Cont>::empty() const
{
    return data.empty();
}

template <typename T, typename Cont>
typename Stack<T, Cont>::size_type Stack<T, Cont>::size() const
{
    return data.size();
}