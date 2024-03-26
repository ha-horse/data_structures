#include "SeqList.hpp"
#include "LinkList.hpp"
#include <iostream>

void testSeqList(){
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

void testLinkList(){
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

int main(){
    std::cout << "test 1:" << std::endl;
    testSeqList();
    std::cout << "test 2:" << std::endl;
    testLinkList();
    return 0;
}
