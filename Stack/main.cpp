#include <iostream>
#include "stack.hpp"  // Include your header
#include <list>

int main() {
    // Default stack using std::list<int>
    Stack<int> s;

    std::cout << "Pushing values 10, 20, 30...\n";
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Current top: " << s.top() << "\n";   // 30
    std::cout << "Size: " << s.size() << "\n";         // 3

    std::cout << "Popping...\n";
    s.pop();
    std::cout << "Current top: " << s.top() << "\n";   // 20

    // Test copy constructor from container.
    std::list<int> lst = {1, 2, 3, 4};
    Stack<int, std::list<int>> s2(lst);

    // std::cout << "\nConstructed stack from list {1,2,3,4}\n";
    // std::cout << "Top: " << s2.top() << "\n";  // 4

    // Test move constructor
    Stack<int, std::list<int>> s3(std::list<int>{100, 200, 300});
    std::cout << "\nMove-constructed stack from list {100,200,300}\n";
    std::cout << "Top: " << s3.top() << "\n";  // 300

    // Test empty and pop until empty
    std::cout << "\nPopping all...\n";
    while (!s3.empty()) {
        std::cout << "Top: " << s3.top() << "\n";
        s3.pop();
    }
    std::cout << "Now empty: " << std::boolalpha << s3.empty() << "\n";

    return 0;
}
