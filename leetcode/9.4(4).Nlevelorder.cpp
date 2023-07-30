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
//N叉树的层序遍历
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL){
            return{};
        }
        vector<vector<int>>result;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int remain = q.size();
            vector<int>mid_result;
            while(remain>0){
                Node*cur = q.front();
                int size = (cur->children).size();
                q.pop();
                remain--;
                mid_result.push_back(cur->val);
                for(int i=0;i<size;i++){
                    q.push((cur->children)[i]);
                }
            }
            result.push_back(mid_result);
        }
        return result;
    }
};