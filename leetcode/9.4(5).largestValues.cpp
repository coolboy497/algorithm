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
//二叉树的每一层的最大值
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<int>result;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>mid_result;
            while(size>0){
                TreeNode*cur = q.front();
                q.pop();
                size--;
                mid_result.push_back(cur->val);
                if(cur->right)q.push(cur->right);
                if(cur->left)q.push(cur->left);
            }
            sort(mid_result.begin(),mid_result.end(),greater<int>());
            result.push_back(*mid_result.begin());
        }
        return result;
    }
};