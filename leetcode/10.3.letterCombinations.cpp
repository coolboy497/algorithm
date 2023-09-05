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
//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。给出数字到字母的映射如下
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
    string code[10]={"","","abc","def","ghi","jkl","mno","qprs","tvu","wxyz"};
    string s;
    vector<string>result;
    void backtraverse(string digits,int index){
        if(index==digits.size()){
            return;
        }
        int dex=digits[index]-'0';
        string zimu = code[dex];
        for(int i=0;i<zimu.length();i++){
            s.push_back(zimu[i]);
            backtraverse(digits,index+1);
            if(s.length()==digits.size()){
                result.push_back(s);
            }
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        backtraverse(digits,0);
        return result;
    }
};