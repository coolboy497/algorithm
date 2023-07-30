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
//后序遍历
//1.递归算法
class Solution {
public:
    void postorder(TreeNode* root,vector<int>&result){
        if(root==NULL){
            return;
        }
        postorder(root->left,result);
        postorder(root->right,result);
        result.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>result;
        postorder(root,result);
        return  result;
    }
};
//2.非递归算法
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL){
            return{};
        }
        vector<int>result;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode*node = st.top();
            st.pop();
            result.push_back(node->val);
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};