#include <iostream>


template<class T>
struct BinaryTreeNode{
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode (const T& data) : data(data) left(nullptr) right(nullptr) {}
};

template<class T>
class BinaryTree {
private:
    BinaryTreeNode *root;
public:
    BinaryTree() : root(nullptr) {}
    BinaryTree(const T& data) {
        root = new BinaryTreeNode<T>(data);
    }
    ~BinaryTree() {
        clear(root);
    }
    bool createTree();
    void clear(BinaryTreeNode<T>* node);
};


template<class T>
bool BinaryTree<T>::createTree() {}

template<class T>
void BinaryTree<T>::clear(BinaryTreeNode<T>* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}
