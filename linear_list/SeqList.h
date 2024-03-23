#include <iostream>

//===================================================
//顺序存储线性表
//===================================================
class LinearList{
private:
    /* data */
    int *buffer; // 动态数组
    int size; // 当前大小
    int capacity; // 容量

    void expand();

public:
    LinearList();
    LinearList(int num, int value = 0);
    ~LinearList();

    //在线性表索引为i的后插入新元素x
    bool insert(const int& x, int i);
    //删除线性表值为x的元素
    bool remove(int x);
    //修改线性表索引为i的元素为x
    bool modify(int x, int i);
    // 获取线性表的长度
    int getLength();

    //查找值为x的元素并返回其索引
    int search(int x) const{
        for (int i = 0; i < size; ++i) {
            if (buffer[i] == x) {
                return i; // 返回匹配元素的索引
            }
        }
        return -1;
    }

    void printList();
    
};
