#include <iostream>
#include "AVL.hpp"

int main() {
    AVL<int> tree;

    std::cout << "=== Inserting elements ===\n";
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(15);
    tree.print();

    std::cout << "\nTree height: " << tree.getHight() << '\n';
    std::cout << "Tree size: " << tree.getSize() << "\n\n";

    std::cout << "=== Searching elements ===\n";
    std::cout << "Search 15: " << (tree.search(15) ? "Found" : "Not found") << '\n';
    std::cout << "Search 99: " << (tree.search(99) ? "Found" : "Not found") << '\n';

    std::cout << "\n=== Minimum and Maximum ===\n";
    Node<int>* minNode = tree.getMin();
    Node<int>* maxNode = tree.getMax();
    if (minNode) std::cout << "Min: " << minNode->data << '\n';
    if (maxNode) std::cout << "Max: " << maxNode->data << '\n';

    std::cout << "\n=== Successor and Predecessor ===\n";
    Node<int>* node = tree.getMin();
    if (node) {
        Node<int>* suc = tree.successor(node);
        if (suc) std::cout << "Successor of " << node->data << " is " << suc->data << '\n';
        else std::cout << "No successor for " << node->data << '\n';
    }

    node = tree.getMax();
    if (node) {
        Node<int>* pre = tree.predecessor(node);
        if (pre) std::cout << "Predecessor of " << node->data << " is " << pre->data << '\n';
        else std::cout << "No predecessor for " << node->data << '\n';
    }

    std::cout << "\n=== Removing elements ===\n";
    tree.remove(10);
    tree.print();
    std::cout << "\nTree size after removing 10: " << tree.getSize() << "\n";

    std::cout << "\n=== Clear tree ===\n";
    tree.clear();
    tree.print();
    std::cout << "\nTree size after clear: " << tree.getSize() << "\n";

    std::cout << "\n=== Initializer list constructor ===\n";
    AVL<int> tree2 = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    tree2.print();
    std::cout << "\nHeight: " << tree2.getHight() << '\n';
    std::cout << "Size: " << tree2.getSize() << '\n';

    return 0;
}
