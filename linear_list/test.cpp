#include "LinearList.h"
#include <iostream>


void printList(LinearList list){
    int *data;
    data = list.getBuffer();
    for (int i = 0; i < list.getLength(); i++)
    {
        std::cout << "第 " << i << " 元素为: " << data[i] << std::endl;
    }
    
}

int main(){
    LinearList list(5);
    list.insert(10, 3);
    printList(list);
    list.modify(8, 0);
    list.modify(8, 1);
    printList(list);
    list.remove(8, 1);
    printList(list);
    return 0;
}
