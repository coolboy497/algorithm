#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
#include <deque>
#include <stack>
#include <ctype.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};
//中序遍历
//1.递归算法
class Solution {
public:
    void inorder(TreeNode* root,vector<int>&result){
        if(root==NULL){
            return;
        }
        inorder(root->left,result);
        result.push_back(root->val);
        inorder(root->right,result);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>result;
        inorder(root,result);
        return  result;
    }
};
//2.非递归算法
class Solution {
public:
    //非递归算法
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<int>result;
        stack<TreeNode*>nums;
        TreeNode*cur = root;
        while(cur||!nums.empty()){
            if(cur){
                nums.push(cur);
                cur=cur->left;
            }
            else{
                cur=nums.top();
                nums.pop();
                result.push_back(cur->val);
                cur=cur->right;
            }
        }
        return result;
    }
};