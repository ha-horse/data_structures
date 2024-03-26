#include "SeqList.hpp"
// #include "LinkList.h"
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

// void testLinkList(){
//     LinkedList list;
//     list.insert(10);
//     list.insert(9);
//     list.printList();
//     std::cout << "----------------" << std::endl;
//     list.modify(8, 0);
//     list.modify(8, 1);
//     list.printList();
//     std::cout << "----------------" << std::endl;
//     list.remove(8);
//     list.printList();
//     std::cout << "----------------" << std::endl;
// }

int main(){
    std::cout << "test 1:" << std::endl;
    testSeqList();
    std::cout << "test 2:" << std::endl;
    // testLinkList();
    return 0;
}
