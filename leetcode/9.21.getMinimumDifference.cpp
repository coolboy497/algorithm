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
//二叉搜索树的最小绝对差
//给你一棵所有节点为非负值的二叉搜索树，
//请你计算树中任意两节点的差的绝对值的最小值
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
    void inorder(TreeNode* root,vector<int>&nums){
            if(!root){
                return;
            }
            inorder(root->left,nums);
            nums.push_back(root->val);
            // inorder(root->left,nums);
            inorder(root->right,nums);
        }
    int getMinimumDifference(TreeNode* root) {
        vector<int>nums;
        inorder(root,nums);
        int min=INT_MAX;
        for(int i=0;i<nums.size()-1;i++){
            if(min>nums[i+1]-nums[i]){
                min=nums[i+1]-nums[i];
            }
        }
        return min;
    }
};