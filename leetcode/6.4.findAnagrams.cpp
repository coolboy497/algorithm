#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <cmath>
using namespace std;
//给定两个字符串s和p，找到s中所有p的异位词的子串
//返回这些子串的起始索引
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int lens = s.length();
        int lenp = p.length();
        if(lens<lenp){
            return {};
        }
        vector<int>result;
        int hash[26];
        for(int i=0;i<26;i++){
            hash[i]=0;
        }
        for(int i=0;i<lenp;i++){
            hash[p[i]-'a']++;
        }
        int copy_hash[26];
        // copy(begin(hash), end(hash), begin(copy_hash));
        int i=0;
        int j=lenp;
        int flag=0;
        while(j<=lens){
            copy(begin(hash), end(hash), begin(copy_hash));
            for(int m=i;m<j;m++){
                copy_hash[s[m]-'a']--;
            }
            for(int k=0;k<26;k++){
                if(copy_hash[k]!=0){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                result.emplace_back(i);
            }
            flag=0;
            i++;
            j++;
        }
        return result;
    }
};
void myprint(int val){
    cout<<val<<"";
}
int main(){
    // vector<int>m(10);默认初始化为10个0；
    // for_each(m.begin(),m.end(),myprint);
    // cout<<endl;
    string s="abab";
    string p="ab";
    Solution s1;
    vector<int>index=s1.findAnagrams(s,p);
    for_each(index.begin(),index.end(),myprint);
    cout<<endl;
    return 0;
}