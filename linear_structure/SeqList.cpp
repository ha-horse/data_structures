#include "SeqList.h"
#include <algorithm>

LinearList::LinearList(){
    buffer = NULL;
    size = 0;
    capacity = 0;
}

LinearList::LinearList(int num, int value){
    size = num;
    capacity = num;
    buffer = new int[capacity];

    for (int i = 0; i < size; i++)
    {
        buffer[i] = value;
    }
    
}

LinearList::~LinearList(){
    // delete []buffer;
}

void LinearList::expand(){
    capacity *= 2;
    int *p = new int[capacity];
    std::copy(buffer, buffer + size, p);
    delete []buffer;
    buffer = p;
}

bool LinearList::insert(const int& x, int index){
    if (size >= capacity) {
            expand();
        }

    for(int i = size - 1; i >= index; i--){
        buffer[i+1] = buffer[i];
    }
    buffer[index] = x;
    size ++;
    return true;
}

bool LinearList::remove(int x){
    if (size == 0)
    {
        return false;
    }

    for (int  i = 0; i < size; i++)
    {
        if (x == buffer[i]) {
            buffer[i] = buffer[i+1];
            size --;
        }
    }
    return true;
    
}

bool LinearList::modify(int x, int index){
    buffer[index] = x;
    return true;
}

int LinearList::getLength(){
    return size;
}

void LinearList::printList(){
    for (int i = 0; i < size; i++)
    {
        std::cout << "第 " << i << " 元素为: " << buffer[i] << std::endl;
    }
    
}
