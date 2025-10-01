#include <iostream>
#include <list>
#include "queue.hpp"

int main() {
    std::cout << "=== Testing default Queue (deque) ===\n";
    Queue<int> q;  // default container: deque

    std::cout << "Enqueue 10, 20, 30...\n";
    q.push(10);
    q.push(20);
    q.push(30);

    std::cout << "Front: " << q.front() << ", Back: " << q.back() << "\n"; // 10,30
    std::cout << "Size: " << q.size() << "\n";

    std::cout << "Dequeue one element...\n";
    q.pop();
    std::cout << "Front: " << q.front() << ", Back: " << q.back() << "\n"; // 20,30
    std::cout << "Size: " << q.size() << "\n";

    std::cout << "\n=== Testing Queue with std::list ===\n";
    std::list<int> lst = {1, 2, 3, 4};
    Queue<int, std::list<int>> qlist(lst);

    std::cout << "Front: " << qlist.front() << ", Back: " << qlist.back() << "\n"; // 1,4
    std::cout << "Size: " << qlist.size() << "\n";

    std::cout << "Dequeue all elements:\n";
    while (!qlist.empty()) {
        std::cout << "Front: " << qlist.front() << ", Back: " << qlist.back() << "\n";
        qlist.pop();
    }
    std::cout << "Now empty? " << std::boolalpha << qlist.empty() << "\n";

    return 0;
}
