#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>
using namespace std;
//给定两个单链表的头节点，找出并返回两个单链表相交的起始节点,是比较指针地址
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
int getlen(ListNode *head){
    ListNode *p = head;
    int len = 0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL||headB==NULL){
            return NULL;
        }
        int lenA = getlen(headA);
        int lenB = getlen(headB);
        int sub = max(lenA,lenB)-min(lenA,lenB);
        ListNode*pa = headA;
        ListNode*pb= headB;
        if(lenA>lenB){
            while(sub>0){
                pa = pa->next;
                sub--;
            }
        }
        if(lenA<lenB){
            while(sub>0){
                pb = pb->next;
                sub--;
            }
        }
        while(pa&&pb&&pa!=pb){
            pa = pa->next;
            pb = pb->next;
        }
        return pa;
    }
};
int main(){
    int nums[5]={4,1,8,4,5};
    int nums2[6]={5,0,1,8,4,5};
    int len = sizeof(nums)/sizeof(nums[0]);
    int len2 = sizeof(nums2)/sizeof(nums2[0]);
    ListNode *headA = createhead(nums,len);
    ListNode *headB = createhead(nums2,len2);
    ListNode *head;
    cout<<"相交的两个链表为:"<<endl;
    printlist(headA);
    cout<<endl;
    printlist(headB);
    cout<<endl;
    Solution s;
    head = s.getIntersectionNode(headA,headB);
    cout<<"相交的节点为:"<<endl;
    printlist(head);
    cout<<endl;
    return 0;
}