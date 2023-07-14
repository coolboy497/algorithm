#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
using namespace std;
//给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 
//needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1
class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.length();
        int len2 = needle.length();
        if(len2==0){
            return 0;
        }
        if(len1<len2||len1==0){
            return -1;
        }
    }
};
void myprint(char c){
    cout<<c<<" ";
}
int main(){
    string s="hello";
    string t="ll";
    Solution s1;
    cout<<"字符串s为:"<<"";
    cout<<s<<endl;
    cout<<"字符串t为:"<<"";
    cout<<t<<endl;
    int result = s1.strStr(s,t);
    cout<<"字符串t在字符串s的位置为:"<<endl;
    cout<<result<<endl;
    cout<<endl;
    return 0;
}