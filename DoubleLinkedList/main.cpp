#include <iostream>
#include "DLL.hpp"

int main() {
    List<int> lst;

    std::cout << "=== Testing push_back ===\n";
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.print_list();

    std::cout << "=== Testing push_front ===\n";
    lst.push_front(5);
    lst.push_front(1);
    lst.print_list();

    std::cout << "=== Testing insert at pos 2 (insert 15) ===\n";
    lst.insert(2, 15);
    lst.print_list();


    std::cout << "=== Testing erase at pos 3 ===\n";
    lst.erase(3);
    lst.print_list();


    std::cout << "=== Testing find (returns Node<T>*) ===\n";
    if (Node<int>* res = lst.find(20))
        std::cout << "Find 20: Found -> " << res->data << "\n";
    else
        std::cout << "Find 20: Not Found\n";

    if (Node<int>* res = lst.find(100))
        std::cout << "Find 100: Found -> " << res->data << "\n";
    else
        std::cout << "Find 100: Not Found\n";

    std::cout << "=== Testing pop_front and pop_back ===\n";
    lst.pop_front();
    lst.pop_back();
    lst.print_list();


    std::cout << "=== Modifying a found value ===\n";
    if (Node<int>* node = lst.find(15)) {
        node->data = 99;
    }
    lst.print_list();

    std::cout << "=== Destructor will be called automatically ===\n";
    return 0;
}
