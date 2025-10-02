#include <iostream>
#include "DLL.hpp"

int main() {
    // Default constructor
    List<int> lst;

    // Push back elements
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);

    // Push front elements
    lst.push_front(5);
    lst.push_front(2);

    // Pop back elements
    lst.pop_back();  // removes 30
    lst.pop_back();  // removes 20

    // Pop front elements
    lst.pop_front(); // removes 2
    lst.pop_front(); // removes 5

    // Copy constructor
    List<int> lst2;
    lst2.push_back(100);
    lst2.push_back(200);
    List<int> lst3(lst2); // copy lst2

    // Move constructor
    List<int> lst4(std::move(lst3));

    // Initializer list
    List<int> lst5 = {1, 2, 3};
    lst5.push_back(4);
    lst5.push_front(0);

    // Pop all elements from lst5
    lst5.pop_front(); // removes 0
    lst5.pop_back();  // removes 4
    lst5.pop_front(); // removes 1
    lst5.pop_front(); // removes 2
    lst5.pop_front(); // removes 3

    std::cout << "All operations completed successfully.\n";
    return 0;
}
