#include "LinkList.h"
#include <cassert>
//===================================================
//链式存储线性表
//===================================================

bool LinkedList::insert(const int& data, int i) {
    assert(i < size || i == 0);
    ListNode* newNode = new ListNode(data);
    if (head == nullptr) {
        head = newNode;
        index = 0;
        size = 1;
    } else {
        ListNode* current = head;
        if (i < size) {
            for (int k = 0; k < i; k++)
            {
                current = current->next;
            }
            current->next = newNode;
            index++;
            size++; 
        }
    }
    return true;
}

bool LinkedList::remove(int x) {
    assert(head != nullptr);
    //当头结点就是要删除的元素
    if (head->data == x) {
        head = head->next;
        size--;
        return true;
    }
    ListNode* current = head;
    for (int i = 0; i < size; i++)
    {
        if (current->next->data == x)
        {
            current->next = current->next->next;
            size--;
        }
        current = current->next;
    }
    return true;
}


int LinkedList::getLength(){
    return size;
}

bool LinkedList::modify(int x, int i){
    assert (i < size);
    ListNode* current = head;
    for (int k = 0; i < size; k++) {
        if (k == i)
        {
            current->data = x;
        }
        current = current->next;
        return true;
    }
    return true;
}

void LinkedList::printList() {
    ListNode* current = head;
    for (int i = 0; i < size; i++)
    {
        std::cout << "第 " << i << " 元素为: " << current->data << std::endl;
        current = current->next;
    }
    
}
