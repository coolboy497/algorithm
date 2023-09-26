#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;
//返回字符串的最长回文子序列长度
//str="a12b3c43def2ghi1kpm"
//"1234321" 返回7
class Solution{
public:
    int longestPalindromeSubseq1(string s){
        if(s.empty()||s.size()==0){
            return 0;
        }
        return subprocess(s,0,s.size()-1);
    }
    //s[left...right]的最长回文子序列的长度
    int subprocess(string s,int left,int right){
        if(left>right){
            return 0;
        }
        if(left==right){
            return 1;
        }
        // (1)left不是,right可能是
        int p1 = subprocess(s,left+1,right);
        // (2)left可能是,right不是
        int p2 = subprocess(s,left,right-1);
        // (3)left和right都可能是
        int p3 = s[left]==s[right] ? 2+subprocess(s,left+1,right-1):0;
        return max(p1,max(p2,p3));
    }

    int longestPalindromeSubseq2(string s){
        if(s.empty()||s.size()==0){
            return 0;
        }
        int N = s.length();
        vector<vector<int>>dp(N,vector<int>(N));
        for(int i=0;i<N;i++){
            dp[i][i]=1;
        }
        for(int i = N-1;i>=0;i--){
            for(int j=i+1;j<N;j++){
                // int p1 = dp[i+1][j];//下面的数
                // int p2 = dp[i][j-1];//左边的数
                // int p3 = s[i]==s[j] ? 2+dp[i+1][j-1]:0;//左下角的数
                // dp[i][j] = max(p1,max(p2,p3));

                // 进一步优化,因为下面和左边的数根据规律是要比左下角的数大的
                dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                if(s[i]==s[j]){
                    dp[i][j] = max(dp[i][j],2+dp[i+1][j-1]);
                }
            }
        }
        return dp[0][N-1];
    }
};
int main(){
    Solution a;
    string str1 = "a12b3c43def2ghi1kpm";
    int num = a.longestPalindromeSubseq1(str1);
    cout<<"num1:"<<num<<endl;

    int num2 = a.longestPalindromeSubseq2(str1);
    cout<<"num2:"<<num2<<endl;
}