#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
using namespace std;
//给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。
//给定的字符串只含有小写英文字母，并且长度不超过10000。

//暴力解法
// class Solution {
// public:
//     bool repeatedSubstringPattern(string s) {
//         int j;
//         for(j=1;j<s.length();j++){
//             if(s[j]!=s[0]){
//                 continue;
//             }
//             else{
//                 int i=0;
//                 int k=j;
//                 int sublen = k-i;
//                 while(k<s.length()&&s[k]==s[i]){
//                     i++;
//                     k++;
//                 }
//                 if(k==s.length()){
//                     int m;
//                     for(m=0;m<sublen;m++){
//                         if(s[m]==s[i]){
//                             i++;
//                         }
//                         else{
//                             break;
//                         }
//                     }
//                     if(m==sublen){
//                         return true;
//                     }
//                     // return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

//移动匹配法
//两个s拼接在一起，里面还出现一个s的话，就说明是由重复子串组成
//要刨除 s + s 的首字符和尾字符，避免搜索到原来的s
// class Solution {
// public:
//     bool repeatedSubstringPattern(string s) {
//         string t = s + s;
//         t.erase(t.begin()); 
//         t.erase(t.end() - 1); // 掐头去尾
//         if (t.find(s) != std::string::npos) return true; // r
//         return false;
//     }
// };

//KMP算法
//在由重复子串组成的字符串中，最长相等前后缀不包含的子串就是最小重复子串
class Solution {
public:
    void getNext (int* next, const string& s){
        next[0] = 0;
        int j = 0;
        for(int i = 1;i < s.size(); i++){
            while(j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if(s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern (string s) {
        if (s.size() == 0) {
            return false;
        }
        int next[s.size()];
        getNext(next, s);
        int len = s.size();
        if (next[len - 1] != 0 && len % (len - (next[len - 1] )) == 0) {
            return true;
        }
        return false;
    }
};
void myprint(char c){
    cout<<c<<" ";
}
int main(){
    string s="aabaaba";
    Solution s1;
    cout<<"字符串s为:"<<"";
    cout<<s<<endl;
    bool result = s1.repeatedSubstringPattern(s);
    if(result){
        cout<<"字符串s可以由其子串重复多次构成"<<endl;
    }
    else{
        cout<<"字符串s不可以由其子串重复多次构成"<<endl;
    }
    return 0;
}