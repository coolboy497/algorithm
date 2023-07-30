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
//二叉树的右视图,返回从右侧所能看到的节点值
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<int>result;
        queue<TreeNode*>q;
        q.push(root);
        int size=0;
        while(!q.empty()){
            size = q.size();
            while(size>0){
                TreeNode*cur = q.front();
                q.pop();
                size--;
                if(size==0){
                    result.push_back(cur->val);
                }
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        return result;
    }
};