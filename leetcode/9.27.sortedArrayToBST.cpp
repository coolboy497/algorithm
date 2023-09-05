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
//给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡二叉搜索树
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
    TreeNode* createdArrayToBST(vector<int>& nums,int left,int right){
        if(left>right){
            return nullptr;
        }
        int mid = (right+left)/2;
        TreeNode*root = new TreeNode(nums[mid]);
        root->left = createdArrayToBST(nums,left,mid-1);
        root->right = createdArrayToBST(nums,mid+1,right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createdArrayToBST(nums,0,nums.size()-1);
    }
};