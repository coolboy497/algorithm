#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>
using namespace std;
//给定一个链表，删除倒数第n个节点，并返回链表头
struct ListNode{
    int val;
    ListNode *next;
    ListNode(ListNode *next1=nullptr){
        val=0;
        next=next1;
    }
};
ListNode *createhead(int nums[],int n){
    ListNode *head = new ListNode;
    head->val = nums[0];
    ListNode *pre = head;
    for(int i=1;i<n;i++){
        ListNode *p = new ListNode;
        p->val = nums[i];
        pre->next = p;
        pre = p;
    }
    return head;
}
void printlist(ListNode *head){
    if(head==nullptr)
    {
        cout<<head<<endl;
    }
    else{
        ListNode *p = head;
        while(p!=NULL){
            cout<<p->val<<"";
            p = p->next;
        }
    }
}
class Solution1 {
public:
    ListNode* reverselist(ListNode* head) {
        ListNode*pre = nullptr;
        ListNode*start = head;
        ListNode*end;
        while(start){
            end = start->next;
            start->next = pre;
            pre = start;
            start=end;
        }
        return pre;
    }
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*p = head;
        for(int i=0;i<n-1;i++){
            p=p->next;
        }
        ListNode*temp = p->next;
        p->next = temp->next;
        delete temp;
        return head;
    }
};
int main(){
    int nums[5]={1,2,3,4,5};
    int n = 2;
    int len = sizeof(nums)/sizeof(nums[0]);
    ListNode *head = createhead(nums,len);
    cout<<"删除前:"<<endl;
    printlist(head);
    cout<<endl;
    Solution1 s1;
    cout<<"翻转"<<endl;
    head = s1.reverselist(head);
    printlist(head);
    cout<<endl;
    Solution s;
    head = s.removeNthFromEnd(head,n);
    cout<<"删除后:"<<endl;
    printlist(head);
    cout<<"翻转"<<endl;
    head = s1.reverselist(head);
    printlist(head);
    cout<<endl;
    return 0;
}