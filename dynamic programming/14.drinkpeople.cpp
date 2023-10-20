#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;
//给定5个参数，N,M,row,col,k表示在N*M的区域上，醉汉Bob初始在(row,col)位置
//Bob一共要迈出k步，且每步都会等概率向上下左右四个方向走一个单位，任何时候Bob只要离开N*M的区域
//就直接死亡,返回k步之后,Bob还在N*M的区域的概率
class Solution{
public:
    double livePosibility(int row,int col,int k,int N, int M){
        return (double) process(row,col,k,N,M)/pow(4,k);
    }
    long process(int row,int col,int rest,int N, int M){
        if(row<0||row==N||col==M||col<0){
            return 0; 
        }
        if(rest==0){
            return 1; 
        }
        int p1 = process(row+1,col,rest-1,N,M);
        int p2 = process(row-1,col,rest-1,N,M);
        int p3 = process(row,col+1,rest-1,N,M);
        int p4 = process(row,col-1,rest-1,N,M);
        return p1+p2+p3+p4;
    }

    //row 0-N
    //col 0-M
    //rest 0-k
    double livePosibility2(int row,int col,int k,int N, int M){
        vector<vector<vector<int>>>dp(N+1,vector<vector<int>>(M+1,vector<int>(k+1)));
        for(int i=0;i<N+1;i++){
            for(int j=0;j<M+1;j++){
                dp[i][j][0]=1;
            }
        }
        //上面一层依赖下面一层
        //所以要先遍历rest
        for(int rest = 1;rest<k+1;rest++){
            for(int i=0;i<N;i++){
                for(int j=0;j<M;j++){
                    int p1 = pick(i+1,j,rest-1,N,M,dp);
                    int p2 = pick(i-1,j,rest-1,N,M,dp);
                    int p3 = pick(i,j+1,rest-1,N,M,dp);
                    int p4 = pick(i,j-1,rest-1,N,M,dp);
                    dp[i][j][rest] = p1+p2+p3+p4;
                }
            }
        }
        return (double) dp[row][col][k]/pow(4,k);
    }
    int pick(int row,int col,int rest,int N, int M,vector<vector<vector<int>>>&dp){
        if(row<0||row==N||col==M||col<0){
            return 0; 
        }
        return dp[row][col][rest];
    }
};
int main(){
    Solution a;
    cout<<a.livePosibility(6, 6, 10, 10, 10)<<endl;
    cout<<a.livePosibility2(6, 6, 10, 10, 10)<<endl;
}