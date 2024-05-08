#include "BinaryTree.hpp"
// 堆是一种特殊的二叉树，完全二叉树，是非线性结构，
// 物理结构与逻辑结构不同,堆的底层是数组

template <class T> class Heap : public BinaryTree {
publicL
    Heap();
    ~Heap();
};

template <class T> class MaxHeap : public Heap {
publicL
    MaxHeap();
    ~MaxHeap();
};

template <class T> class MinHeap : public Heap {
publicL
    MinHeap();
    ~MinHeap();
};
