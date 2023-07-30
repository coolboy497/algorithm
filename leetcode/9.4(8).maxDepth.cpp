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
//给定一个二叉树,找出其最大深度
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class solution {
public:
    //递归算法
    int getdepth(TreeNode* node) {
        if (node == NULL) return 0;
        int leftdepth = getdepth(node->left);       // 左
        int rightdepth = getdepth(node->right);     // 右
        int depth = 1 + max(leftdepth, rightdepth); // 中
        return depth;
    }
    int maxDepth(TreeNode* root) {
        return getdepth(root);
    }
};
class Solution {
public:
    //非递归算法
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int maxDepth=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size>0){
                TreeNode *cur = q.front();
                q.pop();
                size--;
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
            maxDepth++;
        }
        return maxDepth;
    }
};