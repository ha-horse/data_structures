#include "LinkList.hpp"

namespace linklist {
template <class T> class Queue : public LinkedList<T> {
private:
  int head;
  int tail;

public:
  // call base class constructor using initialization list
  Queue() : LinearList<T>(), head(0), tail(0) {}
  Queue(int size) : LinearList<T>(size), head(0), tail(0) {}

  template <class U> friend void printQueue(Queue<U> &queue);

  void enqueue(T value) {
    assert(tail < this->capacity || this->capacity == 0);
    assert(this->insert(value, 0));
    tail++;
  }

  int dequeue() {
    assert(head < tail);
    this->remove(this->buffer[head], true);
    return this->buffer[head++];
  }

  bool isEmpty() const { return head == tail; }
};

template <typename U> void printQueue(Queue<U> &queue) {
  for (int i = 0; i < queue.size; i++) {
    std::cout << "第 " << i << " 元素为: " << queue.buffer[i] << std::endl;
  }
};
} // namespace linklist