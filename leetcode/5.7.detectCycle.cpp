#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>
using namespace std;
// 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null
// 思路：一个快指针，每次走两个节点；一个慢指针，每次走一个节点, 有环的话两个指针终会相遇
struct ListNode{
    int val;
    ListNode *next;
    ListNode(ListNode *next1=nullptr){
        val=0;
        next=next1;
    }
};
ListNode *createcyclehead(int nums[],int n,int index){
    ListNode *head = new ListNode;
    head->val = nums[0];
    ListNode*index1;
    ListNode *pre = head;
    for(int i=1;i<n;i++){
        if(index==i-1){
            index1 = pre;
        }
        ListNode *p = new ListNode;
        p->val = nums[i];
        pre->next = p;
        pre = p;
    }
    pre->next = index1;
    return head;
}
void printcyclelist(ListNode *head,int n){
    if(head==nullptr)
    {
        cout<<head<<endl;
    }
    else{
        ListNode *p = head;
        while(n>0){
            cout<<p->val<<"";
            p = p->next;
            n--;
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
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode*fast,*slow;
        slow = fast = head;
        while(fast&&fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            // 快慢指针相遇，此时从head 和 相遇点，同时查找直至相遇
            if(slow==fast){
                ListNode*p,*q;
                p=head;
                q=slow;
                while(p!=q){
                    p=p->next;
                    q=q->next;
                }
                return p;
            }
        }
        return NULL;
    }
};
int main(){
    int nums[4]={3,2,0,-4};
    int index = 1;
    int len = sizeof(nums)/sizeof(nums[0]);
    ListNode *head = createcyclehead(nums,len,index);
    cout<<"环形链表为:"<<endl;
    printcyclelist(head,len+1);
    cout<<endl;
    Solution s;
    ListNode *head1 = s.detectCycle(head);
    cout<<"环形的起始节点为:"<<endl;
    printcyclelist(head1,len);
    cout<<endl;
    return 0;
}