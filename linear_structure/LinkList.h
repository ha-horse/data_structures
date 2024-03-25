#include <iostream>
//===================================================
//链式存储线性表
//===================================================
struct ListNode {
    int data;
    ListNode* next;
 
    ListNode(const int& data) : data(data), next(nullptr) {}
};
 
class LinkedList {
private:
    ListNode* head;
    int size; //当前链表的长度
    int index; //当前节点的索引
 
public:
    LinkedList(){
        head = nullptr;
        index = 0;
        size = 0;
    }
 
    // 插入节点
    bool insert(const int& data, int i=0);
    // 删除节点
    bool remove(int x);
    // 修改节点
    bool modify(int x, int i);
    int getLength();
    int search(int x) const{
        int index = 0;
        ListNode* current = head;
        for (int i = 0; i < size; i++)
        {
            if (x == current->data)
            {
                return index;
            }
            current = current->next;
            index ++;
        }
        return -1;
        
    }
    void printList();
    
};