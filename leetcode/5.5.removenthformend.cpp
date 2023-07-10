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
//翻转链表思路，相当于删除正着数第几个
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode*new_head= reverselist(head);
//         if(new_head==NULL){
//             return new_head;
//         }
//         if(n==1){
//             new_head = new_head->next;
//             head = reverselist(new_head);
//             return head;
//         }
//         ListNode*p = new_head;
//         for(int i=1;i<n-1;i++){
//             p=p->next;
//         }
//         ListNode*temp = p->next;
//         p->next = temp->next;
//         delete temp;
//         head = reverselist(new_head);
//         return head;
//     }
// };

//先遍历一遍求出长度L,相当于正着删除第L-n+1个节点(加个虚拟头节点更好)
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         if(head==NULL){
//             return head;
//         }
//         int lenL=0;
//         ListNode *p = head;
//         while(p){
//             lenL++;
//             p=p->next;
//         }
//         if(lenL==1){
//             return NULL;
//         }
//         if(lenL==n){
//             return head->next;
//         }
//         p = head;
//         for(int i=1;i<lenL-n;i++){
//             p = p->next;
//         }
//         ListNode * temp = p->next;
//         p->next = temp->next;
//         delete temp;
//         return head;
//     }
// };

// 双指针法,当p,q两指针相距为n，当q为null时，p指针指向倒数第n个节点的前一个节点
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*dummpy_head = new ListNode;
        dummpy_head->next = head;
        ListNode*p,*q;
        p=q=dummpy_head;
        for(int i=0;i<=n;i++){
            q=q->next;
        }
        while(q){
            p=p->next;
            q=q->next;
        }
        ListNode*temp = p->next;
        p->next=temp->next;
        delete temp;
        return dummpy_head->next;
    }
};
int main(){
    int nums[1]={1};
    int n = 1;
    int len = sizeof(nums)/sizeof(nums[0]);
    ListNode *head = createhead(nums,len);
    cout<<"删除前:"<<endl;
    printlist(head);
    cout<<endl;
    Solution s;
    head = s.removeNthFromEnd(head,n);
    cout<<"删除后:"<<endl;
    printlist(head);
    cout<<endl;
    return 0;
}