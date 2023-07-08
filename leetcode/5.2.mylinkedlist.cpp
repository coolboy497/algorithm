#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>
using namespace std;
struct ListNode{
    int val;
    ListNode*next;
};
class MyLinkedList {
public:
    MyLinkedList() {
        this->size = 0;
        this->head = new ListNode;
        this->head->val = -1;
        this->head->next = NULL;
    }
    
    int get(int index) {
        if(index>=size||index<0){
            return -1;
        }
        ListNode *p = head;
        for(int i=0;i<=index;i++){
            p = p->next;
        }
        return p->val;
    }
    
    void addAtHead(int val) {
        ListNode *p = new ListNode;
        p->val = val;
        p->next = head->next;
        head->next = p;
        size++;
        // addAtIndex(0,val);
    }
    
    void addAtTail(int val) {
        ListNode *pre = head;
        while(pre->next){
            pre=pre->next;
        }
        ListNode *p = new ListNode;
        p->val = val;
        p->next = NULL;
        pre->next = p;
        size++;
        // addAtIndex(size,val);
    }
    
    void addAtIndex(int index, int val) {
        if(index>size){
            return;
        }
        if(index==size){
            addAtTail(val);
            return;
        }
        // index = max(0,index);
        ListNode *p = new ListNode;
        p->val = val;
        ListNode *t = head;
        for(int i=0;i<index;i++){
            t=t->next;
        }
        p->next = t->next;
        t->next = p;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index>=size||index<0){
            return;
        }
        size--;
        ListNode *t = head;
        for(int i=0;i<index;i++){
            t=t->next;
        }
        ListNode *p = t->next;
        t->next = t->next->next;
        delete p;
        // size--;
    }
    int size;
    ListNode *head;
};
int main(){
    MyLinkedList mylist;
    mylist.addAtHead(7);
    // mylist.addAtTail(4);
    mylist.addAtHead(2);
    mylist.addAtHead(1);
    mylist.addAtIndex(3,0);
    mylist.deleteAtIndex(2);
    mylist.addAtHead(4);
    mylist.addAtTail(4);
    int num=mylist.get(4);
    cout<<num<<endl;
    mylist.addAtHead(4);
    mylist.addAtIndex(5,0);
    mylist.addAtHead(6);
}