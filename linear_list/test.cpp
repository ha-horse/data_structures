#include "SeqList.h"
#include "LinkList.h"
#include <iostream>

void testSeqList(){
    LinearList list(5);
    list.insert(10, 3);
    list.printList();
    std::cout << "----------------" << std::endl;
    list.modify(8, 0);
    list.modify(8, 1);
    list.printList();
    std::cout << "----------------" << std::endl;
    list.remove(8);
    list.printList();
    std::cout << "----------------" << std::endl;
}

void testLinkList(){
    LinkedList list;
    list.insert(10);
    list.insert(9);
    list.printList();
    std::cout << "----------------" << std::endl;
    list.modify(8, 0);
    list.modify(8, 1);
    list.printList();
    std::cout << "----------------" << std::endl;
    list.remove(8);
    list.printList();
    std::cout << "----------------" << std::endl;
}

int main(){
    std::cout << "test 1:" << std::endl;
    testSeqList();
    std::cout << "test 2:" << std::endl;
    testLinkList();
    return 0;
}
