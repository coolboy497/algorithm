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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL){
            return root;
        }
        swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
class Solution {
public:
    //非递归算法
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL){
            return root;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size>0){
                TreeNode * cur = q.front();
                q.pop();
                size--;
                swap(cur->left,cur->right);
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
        }
        return root;
    }
};