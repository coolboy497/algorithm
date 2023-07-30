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
//给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，
//这条路径上所有节点值相加等于目标和
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
    bool getpath(TreeNode* root,vector<int>&path,int targetSum){
        path.push_back(root->val);
        if(!root->left&&!root->right){
            if(accumulate(path.begin(),path.end(),0)==targetSum)
            {
                return true;
            }
        }
        if(root->left)
        {
            bool leftresult=getpath(root->left,path,targetSum);
            if(leftresult){
                return leftresult;
            }
            else{
                path.pop_back();
            }
        }
        if(root->right){
            bool rightresult=getpath(root->right,path,targetSum);
            if(rightresult){
                return rightresult;
            }
            else{
                path.pop_back();
            }
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root){
            return false;
        }
        vector<int>path;
        bool result = getpath(root,path,targetSum);
        return result;
    }
};