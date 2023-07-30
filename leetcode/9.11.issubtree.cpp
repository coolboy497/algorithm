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
//判断一棵树是否是另一棵树的子树
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
    bool issame(TreeNode* p, TreeNode* q)
    {
        //终止条件
        if(p==nullptr&&q==nullptr) return true;
        else if(p==nullptr&&q!=nullptr) return false;
        else if(p!=nullptr&&q==nullptr) return false;
        else if(p->val!=q->val) return false;
        //进行递归
        bool leftside=issame(p->left,q->left);
        bool rightside=issame(p->right,q->right);
        return leftside&&rightside;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
         //迭代法进行前序遍历
         queue<TreeNode*> q;
         q.push(root);
         bool is_same;
         while(!q.empty())
         {
             TreeNode* node=q.front();
             q.pop();
             if(node->val==subRoot->val)
             {
                 is_same=issame(node,subRoot);
                 if(is_same) return is_same;
             }
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
         }
         return false;
    }
};