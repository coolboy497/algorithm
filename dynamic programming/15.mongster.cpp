#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;
//给定3个参数 N,M,K 怪兽有N滴血，等着英雄来砍自己
//英雄每一次打击，都会让怪兽流失[0~M]的血量
//到底流失多少？每一次在[0~M]上等概率的获得一个值
//求k次打击之后，英雄把怪兽砍死的概率
class Solution{
public:
    double right(int N, int M, int K){
        if(N<1||M<1||K<1){
            return 0;
        }
        long all = pow(M+1,K);
        long kill = process(N,M,K);
        // cout<<"all:"<<all<<endl;
        // cout<<"kill:"<<kill<<endl;
        return (double) kill/ (double)all;
    }
    long process(int N, int M, int K){
        if(N<0){
            return pow(M+1,K);
        }
        if(K==0){
            return N<=0 ? 1 : 0;
        }
        long num = 0;
        for(int i=0;i<M+1;i++){
            num+=process(N-i,M,K-1);
        }
        return num;
    }

    double right2(int N, int M, int K){
        if(N<1||M<1||K<1){
            return 0;
        }
        long all = pow(M+1,K);
        vector<vector<int>>dp(N+1,vector<int>(K+1));
        dp[0][0]=1;
        for(int j=1;j<=K;j++){
            for(int i=0;i<=N;i++){
                long num = 0;
                for(int q=0;q<M+1;q++){
                    num+=pick(i-q,j-1,M,dp);
                    //num+=dp[i-q][j-1];
                }
                dp[i][j] = num;
            }
        }
        return (double) dp[N][K]/ (double)all;
    }
    int pick(int i,int j,int M,vector<vector<int>>&dp){
        if(i<0){
            return pow(M+1,j);
        }
        return dp[i][j];
    }
};
int main(){
    Solution a;
    cout<<a.right(5,10,4)<<endl;
    cout<<a.right2(5,10,4);
}