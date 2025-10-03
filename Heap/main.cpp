#include <iostream>
#include "maxHeap.hpp"   // Include your heap class

int main() {
    // Test with initial vector
    std::vector<int> data = {3, 1, 6, 5, 2, 4};
    max_heap<int> heap(data);

    std::cout << "Top element (max): " << heap.top() << std::endl;

    // Test extract_top repeatedly
    std::cout << "Extracting elements in order:\n";
    while (true) {
        try {
            int max = heap.extract_top();
            std::cout << max << " ";
        } catch (const std::out_of_range& e) {
            break; // Heap is empty
        }
    }
    std::cout << std::endl;

    // Test push
    heap.push(10);
    heap.push(15);
    heap.push(7);
    std::cout << "New top after push: " << heap.top() << std::endl;

    // Extract new elements
    std::cout << "Extracting again:\n";
    while (true) {
        try {
            int max = heap.extract_top();
            std::cout << max << " ";
        } catch (const std::out_of_range& e) {
            break; // Heap is empty
        }
    }
    std::cout << std::endl;

    return 0;
}
