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
#include <queue>
using namespace std;
//给定一个二叉树的根节点root
//翻转这棵二叉树，并返回其根节点
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    //递归算法
    bool compare(TreeNode*left,TreeNode*right){
        if(!left&&right)return false;
        else if(!right&&left)return false;
        else if(!right&&!left)return true;
        else if(left->val!=right->val)return false;
        bool result1 = compare(left->left,right->right);
        bool result2 = compare(left->right,right->left);
        return result1 && result2;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        bool result = compare(root->left,root->right);
        return result;
    }
};
class Solution {
public:
    //非递归算法
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        queue<TreeNode*>q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()){
            TreeNode*left = q.front();
            q.pop();
            TreeNode*right = q.front();
            q.pop();
            if(!left&&!right){
                continue;
            }
            else if(!left||!right||left->val!=right->val){
                return false;
            }
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }
};