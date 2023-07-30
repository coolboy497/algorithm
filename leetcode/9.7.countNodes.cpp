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
//给定一棵完全二叉树，求出该树的节点个数
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
    int countNodes(TreeNode* root) {
       if(root==NULL){
           return 0;
       }
       int leftnodes=countNodes(root->left);
       int rightnodes=countNodes(root->right);
       int result = 1+leftnodes+rightnodes;
       return result;
    }
};