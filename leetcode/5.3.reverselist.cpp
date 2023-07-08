#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>
using namespace std;
//给出单链表的头结点，反转链表
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
    ListNode *pre = head;
    for(int i=0;i<n;i++){
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
        ListNode *p = head->next;
        while(p!=NULL){
            cout<<p->val<<"";
            p = p->next;
        }
    }
}
//定义新链表浪费空间
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode *newhead = new ListNode;
//         if(head==nullptr){
//             return head;
//         }
//         ListNode *p = head->next;
//         while(p){
//             ListNode *t = new ListNode;
//             t->val = p->val;
//             t->next = newhead->next;
//             newhead->next = t;
//             p=p->next;
//         }
//         return newhead;
//     }
// };
// 有头结点的双指针
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head->next;
        ListNode* pre = nullptr;
        while(cur){
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur =  tmp;
        }
        ListNode* new_head = new ListNode;
        new_head->next = pre;
        return new_head;
    }
};
int main(){
    int nums[5]={1,2,3,4,5};
    int len = sizeof(nums)/sizeof(nums[0]);
    ListNode *head = createhead(nums,len);
    cout<<"反转前:"<<endl;
    printlist(head);
    cout<<endl;
    Solution s;
    head = s.reverseList(head);
    cout<<"反转后:"<<endl;
    printlist(head);
    cout<<endl;
    return 0;
}