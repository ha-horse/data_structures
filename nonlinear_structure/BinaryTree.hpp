#include <iostream>

template <class T> struct BinaryTreeNode {
  T data;
  BinaryTreeNode<T> *left;
  BinaryTreeNode<T> *right;

  BinaryTreeNode(const T &data) : data(data), left(nullptr), right(nullptr) {}
};

template <class T> class BinaryTree {
private:
  BinaryTreeNode<T> *root; // 二叉树的根节点

  BinaryTreeNode<T> *insertRecursive(BinaryTreeNode<T> *node, T value);
  BinaryTreeNode<T> *removeRecursive(BinaryTreeNode<T> *node, T value);
  BinaryTreeNode<T> *minValueNode(BinaryTreeNode<T> *node);
  void modifyRecursive(BinaryTreeNode<T> *node, T value, int i);
  // bool researchRecursive(BinaryTreeNode<T> *node, T value) const;
  void preOrderHelper(BinaryTreeNode<T> *node);
  void inOrderHelper(BinaryTreeNode<T> *node);
  void postOrderHelper(BinaryTreeNode<T> *node);

public:
  BinaryTree() : root(nullptr) {}
  BinaryTree(const T &data) { root = new BinaryTreeNode<T>(data); }
  ~BinaryTree() { clear(root); }

  void insert(T value);
  void remove(T value);
  void modify(T value, int i);
  // bool research(T value) const;
  bool research(T value);

  // 二叉树的前序遍历:访问根节点 -> 遍历左子树 -> 遍历右子树
  void preOrderTraversal();
  // 二叉树的中序遍历：遍历左子树 -> 访问根节点 -> 遍历右子树
  void inOrderTraversal();
  // 二叉树的后序遍历：遍历左子树 -> 遍历右子树 -> 访问根节点
  void postOrderTraversal();

  void clear(BinaryTreeNode<T> *node);
};

template <class T>
BinaryTreeNode<T> *BinaryTree<T>::insertRecursive(BinaryTreeNode<T> *node,
                                                  T value) {
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

template <class T> void BinaryTree<T>::insert(T value) {
  root = insertRecursive(root, value);
}

template <class T>
BinaryTreeNode<T> *BinaryTree<T>::removeRecursive(BinaryTreeNode<T> *node,
                                                  T value) {
  if (node == nullptr)
    return nullptr;

  if (value < node->data) {
    node->left = removeRecursive(node->left, value);
  } else if (value > node->data) {
    node->right = removeRecursive(node->right, value);
  } else { // 找到了需要删除的节点
    // 没有孩子或只有一个孩子的情况
    if (node->left == nullptr) {
      BinaryTreeNode<T> *temp = node->right;
      delete node;
      return temp;
    } else if (node->right == nullptr) {
      BinaryTreeNode<T> *temp = node->left;
      delete node;
      return temp;
    }

    // 有两个孩子的情况：用右子树的最小值（或左子树的最大值）替换当前值，并递归删除那个替换过来的节点
    BinaryTreeNode<T> *temp = minValueNode(node->right);
    node->data = temp->data;
    node->right = removeRecursive(node->right, temp->data);
  }
  return node;
}

template <class T>
BinaryTreeNode<T> *BinaryTree<T>::minValueNode(BinaryTreeNode<T> *node) {
  BinaryTreeNode<T> *current = node;
  while (current && current->left != nullptr) {
    current = current->left;
  }
  return current;
}

template <class T> void BinaryTree<T>::remove(T value) {
  root = removeRecursive(root, value);
}

template <class T>
void BinaryTree<T>::modifyRecursive(BinaryTreeNode<T> *node, T value, int i) {
  if (node == nullptr)
    return;

  modifyRecursive(node->left, value, i);
  // 假设是修改节点的数据为i（或根据i的值进行特定的行为修改）
  if (node->data == value) {
    node->data = i; // 此处的修改逻辑依据需求变化
  }
  modifyRecursive(node->right, value, i);
}

template <class T> void BinaryTree<T>::modify(T value, int i) {
  modifyRecursive(root, value, i);
}

// template <class T>
// bool BinaryTree<T>::researchRecursive(BinaryTreeNode<T> *node, T value) const {
//   if (node == nullptr) {
//     return false;
//   }
//   if (node->data == value) {
//     return true;
//   }
//   return researchRecursive(node->left, value) ||
//          researchRecursive(node->right, value);
// }

// template <class T> bool BinaryTree<T>::research(T value) const {
//   return researchRecursive(root, value);
// }

// 上述的代码使用的是递归的方式，而使用递归会导致效率不高。
// 恰巧这段代码又是尾递归的方式（尾递归就是程序分支的最后，也就是最后要返回的时候才出现递归），
// 从编译的角度来讲，尾递归都可以用循环的方式去实现。
// 由于非递归函数的执行效率高，可将“尾递归”函数改为迭代函数。
template <class T> bool BinaryTree<T>::research(T value) {
  BinaryTreeNode<T> *node = root;
  while (node)
  {
    if (value > node->data) node = node->right;
    else if (value < node->data) node = node->left;
    else return true;    
  }
  return false;
}

template <class T> void BinaryTree<T>::preOrderHelper(BinaryTreeNode<T> *node) {
  if (node != nullptr) {
    std::cout << node->data << " "; // 访问根节点
    preOrderHelper(node->left);     // 遍历左子树
    preOrderHelper(node->right);    // 遍历右子树
  }
}

template <class T> void BinaryTree<T>::inOrderHelper(BinaryTreeNode<T> *node) {
  if (node != nullptr) {
    preOrderHelper(node->left);     // 遍历左子树
    std::cout << node->data << " "; // 访问根节点
    preOrderHelper(node->right);    // 遍历右子树
  }
}

template <class T>
void BinaryTree<T>::postOrderHelper(BinaryTreeNode<T> *node) {
  if (node != nullptr) {
    preOrderHelper(node->left);     // 遍历左子树
    preOrderHelper(node->right);    // 遍历右子树
    std::cout << node->data << " "; // 访问根节点
  }
}

template <class T> void BinaryTree<T>::preOrderTraversal() {
  preOrderHelper(root);
}

template <class T> void BinaryTree<T>::inOrderTraversal() {
  inOrderHelper(root);
}

template <class T> void BinaryTree<T>::postOrderTraversal() {
  postrderHelper(root);
}

template <class T> void BinaryTree<T>::clear(BinaryTreeNode<T> *node) {
  if (node) {
    clear(node->left);
    clear(node->right);
    delete node;
  }
}
