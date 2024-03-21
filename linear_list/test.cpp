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
    printf("init linearList filshed!\n");
    list.insert(10, 2);
    printList(list);
    return 0;
}
