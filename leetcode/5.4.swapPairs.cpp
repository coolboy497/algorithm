#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>
using namespace std;
//给定一个链表，两两交换其中相邻的节点[1,2,3,4]->[2,1,4,3]
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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr){
            return head;
        }
        ListNode*start = new ListNode;
        ListNode*new_head = new ListNode;
        start->next= head;
        new_head = start;
        ListNode*mid;
        ListNode*end;
        while(start->next&&start->next->next){
            mid = start->next;
            end = mid->next;
            mid->next = end->next;
            start->next = end;
            end->next = mid;
            start = start->next->next;
        }
        return new_head->next;
    }
};
int main(){
    int nums[4]={1,2,3,4};
    int len = sizeof(nums)/sizeof(nums[0]);
    ListNode *head = createhead(nums,len);
    cout<<"交换前:"<<endl;
    printlist(head);
    cout<<endl;
    Solution s;
    head = s.swapPairs(head);
    cout<<"交换后:"<<endl;
    printlist(head);
    cout<<endl;
    return 0;
}