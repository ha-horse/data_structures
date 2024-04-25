#include "BinaryTree.hpp"
#include <iostream>

void test_binaryTree() {
  BinaryTree<int> *binary_tree = new BinaryTree<int>(10);
  binary_tree->insert(9);
  binary_tree->insert(8);
  binary_tree->modify(7, 1);
  binary_tree->preOrderTraversal();
  binary_tree->inOrderTraversal();
  binary_tree->postOrderTraversal();
  std::cout << "--------------------------\n";
  binary_tree->remove(7);
  binary_tree->preOrderTraversal();
  binary_tree->inOrderTraversal();
  binary_tree->postOrderTraversal();
}

int main() { return 0; }
