

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

    //在线性表第i个元素后插入新元素x
    bool insert(int x, int i);
    //删除线性表的第i个元素
    bool remove(int &x, int i);
    //修改线性表的第i个元素为x
    bool modify(int x, int i);
    // 获取线性表的长度
    int getLength();
    // 获取线性表的数据
    int* getBuffer();
    //查找值为x的元素并返回其位置序号
    int search(int x) const{
        for (int i = 0; i < this->size; ++i) {
            if (this->buffer[i] == x) {
                return i; // 返回匹配元素的索引
            }
        }
        return -1;
    }
    
};

