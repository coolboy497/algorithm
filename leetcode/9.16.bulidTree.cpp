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
//根据一棵树的中序遍历与后序遍历构造二叉树
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
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size()==0)return NULL;
        int midvalue = postorder[postorder.size()-1];
        TreeNode* root = new TreeNode(midvalue);
        if(root==NULL){
            return root;
        }
        int index=0;
        for(index=0;index<inorder.size();index++){
            if(inorder[index]==midvalue){
                break;
            }
        }
        vector<int>inorderleft(inorder.begin(),inorder.begin()+index);
        vector<int>inorderright(inorder.begin()+index+1,inorder.end());
        // 后序遍历数组舍弃末尾元素
        postorder.resize(postorder.size()-1);
        vector<int>postorderleft(postorder.begin(),postorder.begin()+inorderleft.size());
        vector<int>postorderright(postorder.begin()+inorderleft.size(),postorder.end());
        root->left=traversal(inorderleft,postorderleft);
        root->right=traversal(inorderright,postorderright);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return NULL;
        return traversal(inorder, postorder);
    }
};