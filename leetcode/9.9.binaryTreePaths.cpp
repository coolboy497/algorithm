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
//给定一个二叉树的根节点root,按任意顺序返回所有从根节点到叶子结点的路径
//叶子节点是指没有子节点的节点
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
    void searchpath(TreeNode*root,vector<int>&path,vector<string>&result){
        path.push_back(root->val);
        if(!root->left&&!root->right){
            string sPath;
            for(int i=0;i<path.size()-1;i++){
                sPath+= to_string(path[i]);
                sPath+="->";
            }
            sPath+=to_string(path[path.size()-1]);
            result.push_back(sPath);
        }
        if(root->left){
            searchpath(root->left,path,result);
            path.pop_back();
        }
        if(root->right){
            searchpath(root->right,path,result);
            path.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>result;
        vector<int>path;
        if(root==NULL){
            return {};
        }
        searchpath(root,path,result);
        return result;
    }
};