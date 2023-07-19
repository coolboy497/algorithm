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
//给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
//在 S 上反复执行重复项删除操作，直到无法继续删除。
//在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
// class Solution {
// public:
//     string removeDuplicates(string s) {
//         if(s.size()<2){
//             return s;
//         }
//         stack<char>st;
//         for(int i=s.length()-1;i>=0;i--){
//             st.push(s[i]);
//         }
//         string t = "";
//         char top = st.top();
//         t+=top;
//         st.pop();
//         while(!st.empty()){
//             if(top!=st.top()){
//                 t+=st.top();
//                 top = st.top();
//                 st.pop();
//             }
//             else{
//                 t.pop_back();
//                 if(!t.empty()){
//                     top=t[t.length()-1];
//                 }
//                 else{
//                     top='\0';
//                 }
//                 st.pop();
//             }
//         }
//         return t;
//     }
// };

//string中本身就存在类似入栈、出栈的接口
class Solution {
public:
    string removeDuplicates(string s) {
       string st;
       for(char ch:s){
            if(!st.empty()&&st.back()==ch){
                st.pop_back();
            }
            else{
                st.push_back(ch);
            }
       }
       return st;
    }
};
int main(){
    string s = "azxxzy";
    Solution s1;
    string result = s1.removeDuplicates(s);
    cout<<result<<endl;
    return 0;
}