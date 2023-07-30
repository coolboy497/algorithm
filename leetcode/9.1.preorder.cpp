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
//前序遍历
//1.递归算法
class Solution {
public:
    void preorder(TreeNode* root,vector<int>&result){
        if(root==NULL){
            return;
        }
        result.push_back(root->val);
        preorder(root->left,result);
        preorder(root->right,result);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorder(root,result);
        return result;
    }
};
//2.非递归算法
class Solution {
public:
    //非递归算法
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*>nums;
        if(root==NULL){
            return result;
        }
        nums.push(root);
        while(!nums.empty()){
            TreeNode* node = nums.top();
            nums.pop();
            result.push_back(node->val);
            if(node->right) nums.push(node->right);
            if(node->left) nums.push(node->left);
        }
        return result;
    }
};