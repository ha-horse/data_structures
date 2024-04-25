#include "SeqList.hpp"
#include <iostream>

namespace seqlist {
template <class T> class Stack : public LinearList<T> {
private:
  T elems;

public:
  Stack() : LinearList<T>() {}
  bool push(T elems);
  bool pop();
  T top() const;
  template <typename U> friend void printStack(Stack<U> &list);

  bool empty() const { return !this->size; }
};

template <class T> bool Stack<T>::push(T elems) {
  bool flag;
  flag = this->insert(elems, 0);
  return flag;
}

template <class T> bool Stack<T>::pop() {
  if (this->size == 0)
    return false;
  this->size--;
  return true;
}

template <class T> T Stack<T>::top() const {
  if (this->size == 0)
    return -1;
  T elems = this->buffer[this->size - 1];
  return elems;
}

template <typename U> void printStack(Stack<U> &list) {
  for (int i = 0; i < list.size; i++) {
    std::cout << "第 " << i << " 元素为: " << list.buffer[i] << std::endl;
  }
}
} // namespace seqlist