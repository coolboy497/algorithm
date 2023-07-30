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
//计算所有左叶子节点的和
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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root||(!root->left&&!root->right)){
            return 0;
        }
        int sum=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*cur = q.front();
            q.pop();
            if(cur->left){
                q.push(cur->left);
                if(!cur->left->left&&!cur->left->right){
                    sum+=cur->left->val;
                }
            }
            if(cur->right){
                q.push(cur->right);
            }
        }
        return sum;
    }
};