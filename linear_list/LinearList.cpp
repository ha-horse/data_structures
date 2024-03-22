#include "LinearList.h"
#include <iostream>
#include <algorithm>

LinearList::LinearList(){
    this->buffer = NULL;
    this->size = 0;
    this->capacity = 0;
}

LinearList::LinearList(int num, int value){
    this->size = num;
    this->capacity = num;
    this->buffer = new int[size];

    for (int i = 0; i < this->size; i++)
    {
        this->buffer[i] = value;
    }
    
}

LinearList::~LinearList(){
    // delete []buffer;
}

void LinearList::expand(){
    this->capacity *= 2;
    int *p = new int[this->capacity];
    std::copy(this->buffer, this->buffer + this->size, p);
    delete []this->buffer;
    this->buffer = p;
}

bool LinearList::insert(int x, int index){
    index--;
    if (size >= capacity) {
            this->expand();
        }

    for(int i = this->size - 1; i >= index; i--){
        this->buffer[i+1] = this->buffer[i];
    }
    this->buffer[index] = x;
    this->size ++;
    return true;
}

bool LinearList::remove(int &x, int index){}

bool LinearList::modify(int x, int index){
    this->buffer[index-1] = x;
}

int LinearList::getLength(){
    return this->size;
}

int* LinearList::getBuffer(){
    return this->buffer;
}
