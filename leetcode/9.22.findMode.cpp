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
//给定一个有相同值的二叉搜索树(BST),找出BST中的所有众数（出现频率最高的元素）
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
    map<int,int>m;
    static bool mycompare(const pair<int,int>&p,const pair<int,int>&q){
        return p.second > q.second;
    }
    void inorder(TreeNode *root){
        if(!root){
            return;
        }
        m[root->val]++;
        inorder(root->left);
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        if(!root)return{};
        vector<int>result;
        inorder(root);
        vector<pair<int,int>>vec(m.begin(),m.end());
        sort(vec.begin(),vec.end(),mycompare);
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second==vec.begin()->second){
                result.push_back(it->first);
            }
        }
        return result;
    }

};