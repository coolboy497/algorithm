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
//给定一个二叉树和一个目标和，
//找到所有从根节点到叶子节点路径总和等于给定目标和的路径
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
    void getpath(TreeNode* root,vector<int>&path,vector<vector<int>>&result,int targetSum){
        path.push_back(root->val);
        if(!root->left&&!root->right){
            if(accumulate(path.begin(),path.end(),0)==targetSum)
            {
                result.push_back(path);
            }
        }
        if(root->left)
        {
            getpath(root->left,path,result,targetSum);
            path.pop_back();
        }
        if(root->right){
            getpath(root->right,path,result,targetSum);
            path.pop_back();
 
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
        {
            return {};
        }
        vector<vector<int>>result;
        vector<int>path;
        getpath(root,path,result,targetSum);
        return result;
    }
};