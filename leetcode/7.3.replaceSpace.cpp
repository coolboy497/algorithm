#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
using namespace std;
//请实现一个函数，把字符串 s 中的每个空格替换成"%20"
class Solution {
public:
    string replaceSpace(string s) {
        int len = s.length();
        if(len==0){
            return "";
        }
        int i=0;
        while(i<s.length()){
            if(s[i]==' '){
                // s[i]='%';
                s.resize(s.length()+2,0);
                for(int k = s.length();k-2>i;k--){
                    s[k]=s[k-2];
                }
                s[i]='%';
                s[i+1]='2';
                s[i+2]='0';
                i+=2;
            }
            else{
                i++;
            }
        }
        return s;
    }
};
void myprint(char c){
    cout<<c<<" ";
}
int main(){
    string s="    ";
    Solution s1;
    cout<<"替换前:"<<endl;
    cout<<s<<endl;
    string result = s1.replaceSpace(s);
    cout<<"替换后:"<<endl;
    cout<<result<<endl;
    cout<<endl;
    return 0;
}