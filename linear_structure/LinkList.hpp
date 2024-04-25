#include <cassert>
#include <iostream>

#pragma once
//===================================================
// Linked storage linear table
//===================================================
namespace linklist {
template <typename T> struct ListNode {
  T data;
  ListNode *next;

  ListNode(const T &data) : data(data), next(nullptr) {}
};

template <typename T> class LinkedList {
private:
  ListNode<T> *head;
  int size;  //当前链表的长度
  int index; //当前节点的索引

public:
  LinkedList() {
    head = nullptr;
    index = 0;
    size = 0;
  }

  // 插入节点
  bool insert(const T &data, int i = 0);
  // 删除节点
  bool remove(T x);
  // 修改节点
  bool modify(T x, int i);
  int getLength();

  template <typename U> friend void printList(LinkedList<U> &list);

  int search(T x) const {
    int index = 0;
    ListNode<T> *current = head;
    for (int i = 0; i < size; i++) {
      if (x == current->data) {
        return index;
      }
      current = current->next;
      index++;
    }
    return -1;
  }
};

template <typename T> bool LinkedList<T>::insert(const T &data, int i) {
  assert(i < size || i == 0);
  ListNode<T> *newNode = new ListNode<T>(data);
  if (head == nullptr) {
    head = newNode;
    index = 0;
    size = 1;
  } else {
    ListNode<T> *current = head;
    if (i < size) {
      for (int k = 0; k < i; k++) {
        current = current->next;
      }
      current->next = newNode;
      index++;
      size++;
    }
  }
  return true;
}

template <typename T> bool LinkedList<T>::remove(T x) {
  assert(head != nullptr);
  //当头结点就是要删除的元素
  if (head->data == x) {
    head = head->next;
    size--;
    return true;
  }
  ListNode<T> *current = head;
  for (int i = 0; i < size; i++) {
    if (current->next->data == x) {
      current->next = current->next->next;
      size--;
    }
    current = current->next;
  }
  return true;
}

template <typename T> int LinkedList<T>::getLength() { return size; }

template <typename T> bool LinkedList<T>::modify(T x, int i) {
  assert(i < size);
  ListNode<T> *current = head;
  for (int k = 0; i < size; k++) {
    if (k == i) {
      current->data = x;
      return true;
    }
    current = current->next;
  }
  return true;
}

template <typename U> void printList(LinkedList<U> &list) {
  ListNode<U> *current = list.head;
  for (int i = 0; i < list.size; i++) {
    std::cout << "第 " << i << " 元素为: " << current->data << std::endl;
    current = current->next;
  }
}
} // namespace linklist
