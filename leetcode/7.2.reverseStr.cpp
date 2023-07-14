#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
using namespace std;
//给定一个字符串 s 和一个整数 k，从字符串开头算起, 每计数至 2k 个字符，就反转这 2k 个字符中的前 k 个字符。
//如果剩余字符少于 k 个，则将剩余字符全部反转。
//如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样
class Solution{
public:
    string reverseStr(string s, int k) {
        int len = s.length();
        int num = len/(2*k);
        int remain = len-num*2*k;
        int left,right,temp;
        for(int i=0;i<num;i++){
            left = i*2*k;
            right = left+k-1;
            while(left<right){
                temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                left++;
                right--;
            }
        }
        if(remain<k){
            left = num*2*k;
            right = len-1;
            while(left<right){
                temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                left++;
                right--;
            }
        }
        else if(k<=remain<2*k){
            left = num*2*k;
            right = num*2*k+k-1;
            while(left<right){
                temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                left++;
                right--;
            }
        }
        return s;
    }
};
void myprint(char c){
    cout<<c<<" ";
}
int main(){
    string s="hello";
    int k = 2;
    Solution s1;
    cout<<"反转前:"<<endl;
    cout<<s<<endl;
    string result = s1.reverseStr(s,k);
    cout<<"反转后:"<<endl;
    cout<<result<<endl;
    cout<<endl;
    return 0;
}