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
#include <numeric>
using namespace std;
//给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)return NULL;
        if(p->val<root->val&&q->val<root->val){
            TreeNode*left = lowestCommonAncestor(root->left,p,q);
            if(left)return left;
        }
        if(p->val>root->val&&q->val>root->val){
            TreeNode*right = lowestCommonAncestor(root->right,p,q);
            if(right) return right;
        }
        return root;
    }
};