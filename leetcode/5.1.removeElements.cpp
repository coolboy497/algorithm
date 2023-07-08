#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>
using namespace std;
//删除链表中所有满足node.val==val的节点，并返回新的头节点
//两步：（1）移除的是头结点（2）移除的是中间节点
struct ListNode
{
    int val;
    ListNode *next;
};
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head != NULL && head->val == val) { // 注意这里不是if
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        if(head==nullptr)
            return head;
        ListNode *pre = head;
        ListNode *p = pre->next;
        // p = pre->next;
        while(p!=NULL){
            if(p->val==val){
                pre->next = p->next;
            }
            else{
                pre = p;
            }
            p = p->next;
        }
        return head;
    }
};
ListNode *createhead(int nums[],int n){
    ListNode *head = new ListNode;
    ListNode *pre = head;
    for(int i=0;i<n;i++){
        ListNode *p = new ListNode;
        p->next = NULL;
        p->val = nums[i];
        pre->next = p;
        pre = p;
        // p->next = NULL;
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
int main(){
    int nums[1]={1};
    int val = 2;
    int len = sizeof(nums)/sizeof(nums[0]);
    ListNode *head = createhead(nums,len);
    printlist(head);
    cout<<endl;
    Solution s;
    ListNode *head1 = s.removeElements(head,val);
    printlist(head1);
    return 0;
}