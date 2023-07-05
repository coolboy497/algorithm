#include <iostream>
#include <vector>
#include <string>
using namespace std;
//给定s和t字符串，如果两者相等，返回TRUE，#代表退格字符
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i,j;
        i = s.size()-1;
        j = t.size()-1;
        int skips = 0;//统计'#'的数量，因为可能遇到连续多个#出现的情况，此时就需要接着跳过
        int skipt = 0;
        while(i>=0||j>=0){
            while(i>=0){
                if(s[i]=='#'){
                    skips++;
                    i--;
                }
                else if(skips>0){
                    skips--;
                    i--;
                }
                else{
                    break;
                }
            }
            while(j>=0){
                if(s[j]=='#'){
                    skipt++;
                    j--;
                }
                else if(skipt>0){
                    skipt--;
                    j--;
                }
                else{
                    break;
                }
            }
            if(i>=0&&j>=0){
                if(s[i]!=t[j]){
                    return false;
                }
            }
            else{
                if(i>=0 || j>=0){
                    return false;
                }
            }
            i--;
            j--;
        }
    }
};
int main(){
    string s = "ab#c";
    string t = "ad#c";
    Solution solution;
    bool result = solution.backspaceCompare(s,t);
    cout<<result<<endl;
    return 0;
}