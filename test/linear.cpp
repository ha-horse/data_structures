#include "LinkList.hpp"
#include "Queue.hpp"
#include "Stack.hpp"

void testSeqList() {
  LinearList<int> list(5);
  list.insert(10, 3);
  printList(list);
  std::cout << "----------------" << std::endl;
  list.modify(8, 0);
  list.modify(8, 1);
  printList(list);
  std::cout << "----------------" << std::endl;
  list.remove(8);
  printList(list);
  std::cout << "----------------" << std::endl;
  std::cout << "----------------" << std::endl;
  LinearList<float> list_float(5);
  list_float.insert(10.2, 3);
  printList(list_float);
  std::cout << "----------------" << std::endl;
  list_float.modify(8.1, 0);
  list_float.modify(8.2, 1);
  printList(list_float);
  std::cout << "----------------" << std::endl;
  list_float.remove(8.1);
  printList(list_float);
  std::cout << "----------------" << std::endl;
}

void testLinkList() {
  LinkedList<int> link;
  link.insert(10);
  link.insert(9);
  printList(link);
  std::cout << "----------------" << std::endl;
  link.modify(8, 0);
  link.modify(8, 1);
  printList(link);
  std::cout << "----------------" << std::endl;
  link.remove(8);
  printList(link);
  std::cout << "----------------" << std::endl;
  std::cout << "----------------" << std::endl;
  LinkedList<float> link_float;
  link_float.insert(10.2);
  link_float.insert(9.2);
  printList(link_float);
  std::cout << "----------------" << std::endl;
  link_float.modify(8.1, 0);
  link_float.modify(8.2, 1);
  printList(link_float);
  std::cout << "----------------" << std::endl;
  link_float.remove(8.1);
  printList(link_float);
  std::cout << "----------------" << std::endl;
}

void testStack() {
  Stack<int> int_stack;
  int_stack.push(10);
  int_stack.push(19);
  printStack(int_stack);
  std::cout << "----------------" << std::endl;
  int value1 = int_stack.top();
  std::cout << "value = " << value1 << std::endl;
  std::cout << "----------------" << std::endl;
  int_stack.pop();
  printStack(int_stack);
  std::cout << "----------------" << std::endl;

  Stack<float> fload_stack;
  fload_stack.push(10.1);
  fload_stack.push(19.2);
  printStack(fload_stack);
  std::cout << "----------------" << std::endl;
  float value2 = fload_stack.top();
  std::cout << "value = " << value2 << std::endl;
  std::cout << "----------------" << std::endl;
  fload_stack.pop();
  printStack(fload_stack);
  std::cout << "----------------" << std::endl;
}

void testQueue() {
  Queue<int> int_queue;
  int_queue.enqueue(10);
  int_queue.enqueue(19);
  printQueue(int_queue);
  std::cout << "----------------" << std::endl;
  int_queue.dequeue();
  printQueue(int_queue);
  std::cout << "----------------" << std::endl;

  Queue<float> fload_queue;
  fload_queue.enqueue(10.1);
  fload_queue.enqueue(19.2);
  printQueue(fload_queue);
  std::cout << "----------------" << std::endl;
  fload_queue.dequeue();
  printQueue(fload_queue);
  std::cout << "----------------" << std::endl;
}
