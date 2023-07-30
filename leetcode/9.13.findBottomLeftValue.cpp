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
//找树左下角的值
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
    int findBottomLeftValue(TreeNode* root) {
        if(!root->left&&!root->right){
            return root->val;
        }
        queue<TreeNode*>q;
        int result;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size>0){
                TreeNode*cur = q.front();
                q.pop();
                size--;
                if(size==0)result=cur->val;
                if(cur->right)q.push(cur->right);
                if(cur->left)q.push(cur->left);
            }
        }
        return result;
    }
};