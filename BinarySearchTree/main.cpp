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

    if(tree.search(13)) {
        std::cout << "13 is here:\n";
    }

    std::cout << "The hight of tree is " << tree.getHight() << std::endl;

    tree.clear();

    tree.insert(17);
    tree.insert(5);
    tree.insert(7);
    tree.insert(2);


    tree.print();
    if(tree.search(13)) {
        std::cout << "13 is here:\n";
    }
    else {
        std::cout << "13 is not here\n";
    }
    
    std::cout << "The hight of tree is " << tree.getHight() << std::endl;

}