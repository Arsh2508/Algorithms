#include <iostream>
#include "BinarySearchTree.hpp"

int main() {
    BinarySearchTree<int> bst;

    // ===== Insert some values =====
    bst.insert(8);
    bst.insert(3);
    bst.insert(10);
    bst.insert(1);
    bst.insert(6);
    bst.insert(14);
    bst.insert(4);
    bst.insert(7);
    bst.insert(13);

    std::cout << "=== Binary Search Tree ===\n";
    bst.print();
    std::cout << "\n";

    // ===== Search =====
    std::cout << "\nSearching for 6: " << (bst.search(6) ? "Found" : "Not Found") << "\n";
    std::cout << "Searching for 15: " << (bst.search(15) ? "Found" : "Not Found") << "\n";

    // ===== Minimum and Maximum =====
    std::cout << "\nMinimum value: " << bst.getMin()->data << "\n";
    std::cout << "Maximum value: " << bst.getMax()->data << "\n";

    // ===== Successor and Predecessor =====
    Node<int>* node = bst.getMin();  // smallest node (1)
    Node<int>* succ = bst.successor(node);
    if (succ)
        std::cout << "\nSuccessor of " << node->data << " is " << succ->data << "\n";
    else
        std::cout << "\n" << node->data << " has no successor\n";

    node = bst.getMax();  // largest node (14)
    Node<int>* pred = bst.predecessor(node);
    if (pred)
        std::cout << "Predecessor of " << node->data << " is " << pred->data << "\n";
    else
        std::cout << node->data << " has no predecessor\n";

    // ===== Tree height =====
    std::cout << "\nHeight of tree: " << bst.getHight() << "\n";

    // ===== Remove elements =====
    std::cout << "\nRemoving 3 (has two children)...\n";
    bst.remove(3);
    bst.print();
    std::cout << "\n";

    std::cout << "\nRemoving 14 (leaf)...\n";
    bst.remove(14);
    bst.print();
    std::cout << "\n";

    std::cout << "\nClearing entire tree...\n";
    bst.clear();
    bst.print();

    return 0;
}
