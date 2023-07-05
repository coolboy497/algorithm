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
        int i=0,j=0;
        // int sublen = s.size()+1;
        int lens = s.size();
        int lent = t.size();
        if(lens < lent){
            return "";
        }
        if(lens==lent&&s!=t){
            return "";
        }
        if(lens==lent&&s==t){
            return s;
        }
        if(lent==1){
            if(s.find(t)!= string::npos)
            {
                return t;
            }
            else{
                return "";
            }
        }
        map <char,int> m;
        for(i=0;i<lens;i++){
            // 判断字符s[i]是否在t中
            if(t.find(s[i]) != string::npos){
                m[s[i]]++;
            }
            while(m.size()==lent){
                auto it = m.find(s[j]);
                if(it->second>1){
                    it->second --;
                }
                else if(it->second==1){
                    break;
                }
                j++;
            }
        }
        if (m.size()==0){
            return "";
        }
        return s.substr(j,i);
    }
};
int main(){
    string s = "abc";
    string t = "ab";
    Solution s1;
    string substr = s1.minWindow(s,t);
    cout<<substr<<endl;
    return 0;
}