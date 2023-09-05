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
//构建最大二叉树
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
    TreeNode* tree(vector<int>&nums,int left,int right){
        // if(nums.size()==0){
        //     return nullptr;
        // }
        // int maxposition = max_element(nums.begin(),nums.end())-nums.begin();
        // int maxvalue = *max_element(nums.begin(),nums.end());
        if(left>=right){
            return nullptr;
        }
        int maxindex = left;
        for(int index=left;index<right;index++){
            if(nums[index]>nums[maxindex]){
                maxindex=index;
            }
        }
        TreeNode*root = new TreeNode(nums[maxindex]);
        // vector<int>left(nums.begin(),nums.begin()+maxposition);
        // vector<int>right(nums.begin()+maxposition+1,nums.end());
        root->left = tree(nums,left,maxindex);
        root->right = tree(nums,maxindex+1,right);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0){
            return{};
        }
        TreeNode*root = tree(nums,0,nums.size());
        return root;
    }
};
int main(){
    vector<int>nums={1,6,8,3,5};
    Solution S;
    S.constructMaximumBinaryTree(nums);
    return 0;
}