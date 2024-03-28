#include <iostream>
#include <algorithm>

// 由于模板的编译方式，模板类的成员函数（包括构造和析构函数）通常都是在头文件中定义的，
// 而不是传统的将声明和定义分别放在头文件（.h或.hpp）和源文件（.cpp）中。
// 这是因为模板需要在编译时实例化，而编译器在处理源文件时无法访问不在同一翻译单元的模板定义。

//===================================================
//顺序存储线性表
//===================================================

template <typename T>
class LinearList{
protected:
    /* data */
    T *buffer; // 动态数组
    int size; // 当前大小
    int capacity; // 容量

    void expand();

public:
    LinearList(); 
    LinearList(int num, T value = 0);
    ~LinearList();

    //在线性表索引为i的后插入新元素x
    bool insert(const T& x, int i);
    //删除线性表值为x的元素
    bool remove(T x);
    //修改线性表索引为i的元素为x
    bool modify(T x, int i);
    // 获取线性表的长度
    int getLength();

    template <typename U>
    friend void printList(LinearList<U>& list);

    //查找值为x的元素并返回其索引
    int search(T x) const{
        for (int i = 0; i < size; ++i) {
            if (buffer[i] == x) {
                return i; // 返回匹配元素的索引
            }
        }
        return -1;
    }
};

template <typename T>
LinearList<T>::LinearList(){
    buffer = NULL;
    size = 0;
    capacity = 0;
}

template <typename T>
LinearList<T>::LinearList(int num, T value){
    size = num;
    capacity = num;
    buffer = new T[capacity];

    for (int i = 0; i < size; i++)
    {
        buffer[i] = value;
    }
    
}

template <typename T>
LinearList<T>::~LinearList(){
    // delete []buffer;
}

template <typename T>
void LinearList<T>::expand(){
    capacity *= 2;
    T *p = new T[capacity];
    std::copy(buffer, buffer + size, p);
    delete []buffer;
    buffer = p;
}

template <typename T>
bool LinearList<T>::insert(const T& x, int index){
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

template <typename T>
bool LinearList<T>::remove(T x){
    if (size == 0)
    {
        return false;
    }

    for (int  i = size - 1; i >= 0; i--)
    {
        if (x == buffer[i]) {
            for (int j = i; j < size - 1; j++)
            {
                buffer[j] = buffer[j+1];
            }
            size --;
        }
    }
    return true;
    
}

template <typename T>
bool LinearList<T>::modify(T x, int index){
    buffer[index] = x;
    return true;
}

template <typename T>
int LinearList<T>::getLength(){
    return size;
}

template <typename U>
void printList(LinearList<U>& list){
    for (int i = 0; i < list.size; i++)
    {
        std::cout << "第 " << i << " 元素为: " << list.buffer[i] << std::endl;
    }
}
