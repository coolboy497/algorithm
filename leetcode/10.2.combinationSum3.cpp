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
//找出所有相加之和为 n 的 k 个数的组合，且满足下列条件
//(1)只使用数字1到9
//(2)每个数字最多使用一次
//返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回
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
    void backtraverse(int k, int n,int startindex,vector<int>&list,vector<vector<int>>&result){
        if(accumulate(list.begin(),list.end(),0)>n){
            return;
        }
        if(accumulate(list.begin(),list.end(),0)==n&&list.size()==k){
            result.push_back(list);
            return;
        }
        for(int i=startindex;i<=9;i++){
            list.push_back(i);
            backtraverse(k,n,i+1,list,result);
            list.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>result;
        vector<int>list;
        backtraverse(k,n,1,list,result);
        return result;
    }
};