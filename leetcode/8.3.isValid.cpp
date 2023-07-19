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
using namespace std;
//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效
// 有效字符串满足：
// 1.左括号必须用相同类型的右括号闭合。
// 2.左括号必须以正确的顺序闭合。
// 3.注意空字符串可被认为是有效字符串。
//思路，遇到一个左括号就入栈其对应的右括号
//遇到右括号就将栈顶元素进行比较
class Solution {
public:
    bool isValid(string s) {
        if(s.length()==0){
            return true;
        }
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(')');
            }
            else if(s[i]=='{'){
                st.push('}');
            }
            else if(s[i]=='['){
                st.push(']');
            }
            else{
                if(!st.empty()&&st.top()==s[i]){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};
int main(){
    string s = "()";
    Solution s1;
    bool result = s1.isValid(s);
    cout<<result<<endl;
    return 0;
}