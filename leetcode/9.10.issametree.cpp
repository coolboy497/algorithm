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
//判断两棵树是否相同
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL&&q==NULL)return true;
        if(p==NULL||q==NULL)return false;
        queue<TreeNode*>que;
        que.push(p);
        que.push(q);
        while(!que.empty()){
            TreeNode*firsttree = que.front();
            que.pop();
            TreeNode*secondtree = que.front();
            que.pop();
            if(!firsttree&&!secondtree){
                continue;
            }
            if ((!firsttree || !secondtree || (firsttree->val != secondtree->val))) {
                return false;
            }
            que.push(firsttree->left);
            que.push(secondtree->left);
            que.push(firsttree->right);
            que.push(secondtree->right);
        }
        return true;
    }
};