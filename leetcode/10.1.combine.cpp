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
//给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合
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
    void backtraversal(int n,int k,int index,vector<int>&collect,vector<vector<int>>&result){
        if(collect.size()==k){
            result.push_back(collect);
            return;
        }
        //index至多从n-(k-collect.size())+1开始才有解
        for(int i=index;i<=n-(k-collect.size())+1;i++){
            collect.push_back(i);
            backtraversal(n,k,i+1,collect,result);
            collect.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        if(n<k)return {};
        vector<vector<int>>result;
        vector<int> collect;
        backtraversal(n,k,1,collect,result);
        return result;
    }
};