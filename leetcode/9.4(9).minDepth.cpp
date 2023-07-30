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
//给定一个二叉树,找出其最小深度
//最小深度是从根节点到最近叶子节点的最短路径上的节点数量
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
    //非递归算法
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int minDepth=1;
        queue<TreeNode*>q;
        q.push(root);
        int k = 0;
        while(!q.empty()){
            int size = q.size();
            while(size>0){
                TreeNode*cur = q.front();
                if(!cur->left&&!cur->right){
                    return minDepth;
                }
                else{
                    q.pop();
                    size--;
                    if(cur->left)q.push(cur->left);
                    if(cur->right)q.push(cur->right);
                }
            }
            minDepth++;
        }
        return minDepth;
    }
};