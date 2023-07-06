#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
// 求s中涵盖t所有字符的最小子串，如果不存在，则返回""
class Solution {
public:
    string minWindow(string s, string t) {
        int lens = s.length();
        int lent = t.length();
        if(lens<lent||lens==0||lent==0){
            return "";
        }
        map<char,int>ms;
        map<char,int>mt;
        for(int i=0;i<lent;i++){
            mt[t[i]]++;
        }
        int left=0,right=0;
        int num=0;
        string substr;
        for(;right<lens;right++){
            ms[s[right]]++;
            if(ms[s[right]]<=mt[s[right]]){
                num++;
            }
            while(ms[s[left]]>mt[s[left]]){
                ms[s[left]]--;
                left++;
            }
            if(num==lent){
                if(substr.empty()||right-left+1<substr.size()){
                    substr = s.substr(left,right-left+1);
                }
            }
        }
        return substr;
    }
};
int main(){
    string s = "abc";
    string t = "b";
    Solution s1;
    string substr = s1.minWindow(s,t);
    cout<<substr<<endl;
    return 0;
}