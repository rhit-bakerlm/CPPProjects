#include <iostream>

#include "EditorTrees.h"

int main() {
    BinaryTree tree = BinaryTree();

    tree.insert(1);
    tree.insert(2);
    tree.insert(-1);

    std::cout << tree.toString() << std::endl;

    tree.remove(2);
    tree.remove(1);
    tree.remove(-1);

    std::cout << tree.toString() << std::endl;
}