#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <cmath>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        int lens = s.length();
        int lent = t.length();
        if(lens!=lent){
            return false;
        }
        unordered_map<char,int>ms;
        unordered_map<char,int>mt;
        for(int i=0;i<lens;i++){
            ms[s[i]]++;
        }
        for(int i=0;i<lent;i++){
            mt[t[i]]++;
        }
        for(int k=0;k<lens;k++){
            if(ms[s[k]]==mt[s[k]]){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词
//即字符串中每个字符出现的个数相等
int main(){
    string s="anagram";
    string t="nagaram";
    Solution s1;
    bool k=s1.isAnagram(s,t);
    if(k){
        cout<<"字符串s和t是字母异位词"<<endl;
    }
    else{
        cout<<"字符串s和t不是字母异位词"<<endl;
    }
    return 0;
}