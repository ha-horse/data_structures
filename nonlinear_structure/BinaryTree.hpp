#include <iostream>


template<class T>
struct BinaryTreeNode{
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode (const T& data) : data(data), left(nullptr), right(nullptr) {}
};

template<class T>
class BinaryTree {
private:
    BinaryTreeNode<T> *root;// 二叉树的根节点

    BinaryTreeNode<T>* insertRecursive(BinaryTreeNode<T> *node, T value);
public:
    BinaryTree() : root(nullptr) {}
    BinaryTree(const T& data) {
        root = new BinaryTreeNode<T>(data);
    }
    ~BinaryTree() {
        clear(root);
    }

    void insert(T value);
    void remove(T value);
    void modify(T value, int i);
    int research(T value) const;

    // 二叉树的前序遍历:访问根节点 -> 遍历左子树 -> 遍历右子树
    void preOrderTraversal();
    // 二叉树的中序遍历：遍历左子树 -> 访问根节点 -> 遍历右子树
    void inOrderTraversal();
    // 二叉树的后序遍历：遍历左子树 -> 遍历右子树 -> 访问根节点
    void postOrderTraversal();

    void clear(BinaryTreeNode<T>* node);
};

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::insertRecursive(BinaryTreeNode<T>* node, T value) {
    if (node == nullptr) {
        return new BinaryTreeNode<T>(value);
    }

    if (value < node->data) {
        node->left = insertRecursive(node->left, value);
    } else if (value > node->data) {
        node->right = insertRecursive(node->right, value);
    }
    return node; // 保持原样如果值已存在
}

template<class T>
void BinaryTree<T>::insert(T value) {
    root = insertRecursive(root, value);
}

template<class T>
void BinaryTree<T>::remove(T value) {}

template<class T>
void BinaryTree<T>::modify(T value, int i) {}

template<class T>
int BinaryTree<T>::research(T value) const {}

template<class T>
void BinaryTree<T>::preOrderTraversal() {
    if (root == nullptr) return;
    std::cout << root->data << " ";
    root = root->left;
    preOrderTraversal()
    root = root->right;
    preOrderTraversal()
}

template<class T>
void BinaryTree<T>::inOrderTraversal() {
    if (root == nullptr) return;
    root = root->left;
    preOrderTraversal();
    std::cout << root->data << " ";
    root = root->right;
    preOrderTraversal();
}

template<class T>
void BinaryTree<T>::postOrderTraversal() {
    if (root == nullptr) return;
    root = root->left;
    preOrderTraversal();
    root = root->right;
    preOrderTraversal();
    std::cout << root->data << " ";
}

template<class T>
void BinaryTree<T>::clear(BinaryTreeNode<T>* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}
