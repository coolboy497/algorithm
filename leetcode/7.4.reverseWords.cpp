#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
using namespace std;
//给定一个字符串，逐个翻转字符串中的每个单词 "hello world"->"world hello"。
//返回的结果字符串中，单词间仅有单个空格
class Solution {
public:
    string reverseWords(string s) {
        int left,right,i=0,j=0,k;
        while(j<s.length()){
            while(isspace(s[j])&&j<s.length()){
                j++;
            }
            // k = j-i-1;//需要消除的空格数
            if(j>i+1){
                for(k = j;k<s.length();k++){
                    s[k-j+i+1]=s[k];
                }
                s.resize(s.length()-j+i+1);
                j=i+1;
            }
            // j=i+1;
            i=j;
            while(!isspace(s[i])&&i<s.length()){
                i++;
            }
            left = j;
            if(i==s.length()-1){
                right = i;
            }
            right = i-1;
            while(left<right){
                swap(s[left],s[right]);
                left++;
                right--;
            }
            j = i;
        }
        //s:"the sky is blue"->"eht yks si eulb"
        cout<<s<<endl;
        reverse(s.begin(),s.end());//"eht yks si eulb"->"blue is sky the"
        //消除后面的空格
        int k2=s.length()-1;
        while(isspace(s[k2])){
            k2--;
        }
        if(k2<s.length()-1){
            s.resize(k2+1);
        }
        //消除前面的空格
        int k1=0;
        while(isspace(s[k1])){
            k1++;
        }
        if(k1!=0){
            for(int i=0;i<s.length()-k1;i++){
                s[i]=s[i+k1];
            }
            s.resize(s.length()-k1);
        }
        return s;
    }
};
void myprint(char c){
    cout<<c<<" ";
}
int main(){
    string s="a good   example";
    Solution s1;
    cout<<"翻转前:"<<endl;
    cout<<s<<endl;
    string result = s1.reverseWords(s);
    cout<<"翻转后:"<<endl;
    cout<<result<<endl;
    cout<<endl;
    return 0;
}