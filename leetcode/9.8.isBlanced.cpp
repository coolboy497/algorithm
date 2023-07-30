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
//判断是否为高度平衡的二叉树
//每个节点的左右两个子树的高度差绝对值不超过1
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
    int getdepth(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftdepth = getdepth(root->left);
        if(leftdepth==-1)return -1;
        int rightdepth = getdepth(root->right);
        if(rightdepth==-1)return -1;
        int result = abs(leftdepth-rightdepth);
        if(result>1){
            return -1;
        }
        return 1+max(leftdepth,rightdepth);
    }
    bool isBalanced(TreeNode* root) {
        int result=getdepth(root);
        if(result==-1){
            return false;
        }
        return true;
    }   
};