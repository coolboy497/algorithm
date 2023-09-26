#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;
//动态规划4种模型
//(1)从左到右
//(2)范围
//(3)样本对应
//(4)业务
//返回最长的公共子序列
//str1: "a12bc345def"
//str2: "MNP123QRS45Z"
//结果: "12345"
class Solution{
public:
    int longestCommonSubsequence1(string str1,string str2){
        if(str1.empty()||str2.empty()){
            return 0;
        }
        return subprocess(str1,str2,str1.size()-1,str2.size()-1);
    }
    //str1[0....i] 与 str2[0....j]的最长公共子序列
    int subprocess(string str1,string str2,int i,int j){
        if(i==0&&j==0){
            return str1[i]==str2[j] ? 1:0;
        }
        else if(i==0){
            if(str2[j]==str1[i]){
                return 1;
            }
            else{
                return subprocess(str1,str2,i,j-1);
            }
        }
        else if(j==0){
            if(str2[j]==str1[i]){
                return 1;
            }
            else{
                return subprocess(str1,str2,i-1,j);
            }
        }
        else{
            // (1)i位置一定不是公共子序列中的，j位置有可能是
            // (2)j位置一定不是公共子序列中的，i位置有可能是
            // (3)i,j位置都有可能是公共子序列中的，看两者是否相等
            int p1 = subprocess(str1,str2,i-1,j);
            int p2 = subprocess(str1,str2,i,j-1);
            int p3 = str1[i]==str2[j] ? (1+subprocess(str1,str2,i-1,j-1)) : 0;
            return max(p1,max(p2,p3));
        }
    }


    int longestCommonSubsequence2(string str1,string str2){
        if(str1.empty()||str2.empty()){
            return 0;
        }
        int M=str1.length();
        int N=str2.length();
        vector<vector<int>>dp(M,vector<int>(N));
        dp[0][0] = str1[0]==str2[0] ? 1:0;
        for(int j=1;j<N;j++){
            dp[0][j]= str2[j]==str1[0] ? 1: dp[0][j-1];
        }
        for(int i=1;i<M;i++){
            dp[i][0]= str2[0]==str1[i] ? 1: dp[i-1][0];
        }
        for(int i = 1;i < M;i++){
            for(int j= 1 ; j<N;j++ ){
                int p1 = dp[i-1][j];
                int p2 = dp[i][j-1];
                int p3 = str1[i]==str2[j] ? (1+dp[i-1][j-1]) : 0;
                dp[i][j]= max(p1,max(p2,p3));
            }
        }
        return dp[M-1][N-1];
    }
    
};
int main(){
    Solution a;
    string str1 = "a12bc345def";
    string str2 = "MNP123QRS45Z";
    int num = a.longestCommonSubsequence1(str1,str2);
    int num2 = a.longestCommonSubsequence2(str1,str2);
    cout<<"num1:"<<num<<endl;
    cout<<"num2:"<<num2<<endl;
}