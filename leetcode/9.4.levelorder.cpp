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
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};
//层序遍历
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
         if(root==NULL){
             return {};
         }
         vector<vector<int>>result;
         queue<TreeNode*>q;
         q.push(root);
         int size;
         while(!q.empty()){
             size=q.size();
             vector<int>mid_result;
             while(size>0){
                 TreeNode*cur = q.front();
                 q.pop();
                 size--;
                 mid_result.push_back(cur->val);
                 if(cur->left) q.push(cur->left);
                 if(cur->right) q.push(cur->right);
             }
             result.push_back(mid_result);
         }
         return result;
    }
};