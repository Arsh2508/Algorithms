#ifndef MAX_HEAP
#define MAX_HEAP
#include <vector>

template <typename T>
class max_heap {
public:

    using size_type = size_t;
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;

    max_heap();
    max_heap(const std::vector<T>& array);
    size_type left(size_type i);
    size_type right(size_type i);
    void MaxHeapify(size_type i);
    void BuildMaxHeap();

    reference top();
    const_reference top() const;

    value_type extract_top();

    void push(const_reference val);
    void pop();

private:
    std::vector<T> arr;
    size_type heap_size;
};

#include "maxHeap.cpp"
#endif