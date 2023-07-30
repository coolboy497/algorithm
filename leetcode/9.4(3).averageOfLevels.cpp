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
//二叉树的层平均值
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<double>result;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int total = size;
            long num=0;
            while(size>0){
                TreeNode*cur = q.front();
                q.pop();
                size--;
                num+=cur->val;
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
            result.push_back(1.0*num/total);
        }
        return result;
    }
};