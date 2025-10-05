#include <iostream>
#include "BinarySearchTree.hpp"

int main()
{
    BinarySearchTree<int> tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(25);
    tree.insert(15);
    tree.insert(13);
    tree.insert(17);
    tree.insert(5);
    tree.insert(7);
    tree.insert(2);
    tree.insert(1);
    tree.print();
}