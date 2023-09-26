#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;
//一个象棋的棋盘，棋盘的最左下角是(0,0)位置，那么整个棋盘就是横坐标上
//9条线、纵坐标上10条线的区域，给你三个参数x、y、k,返回"马"从(0,0)位置出发
//必须走k步,最后落到(x,y)上的方法数有多少种?
class Solution{
public:
    int ways(int x,int y,int a,int b,int step){
        return jump(x,y,step,a,b);
    }
    int jump(int x,int y,int rest,int i,int j){
        if(i>9||j>8||i<0||j<0){
            return 0;
        }
        if(rest==0){
            return i==x&&j==y ? 1:0;
        }
        int p1 = jump(x,y,rest-1,i-1,j+2);
        int p2 = jump(x,y,rest-1,i+1,j+2);
        int p3 = jump(x,y,rest-1,i-2,j-1);
        int p4 = jump(x,y,rest-1,i-2,j+1);
        int p5 = jump(x,y,rest-1,i-1,j-2);
        int p6 = jump(x,y,rest-1,i+1,j-2);
        int p7 = jump(x,y,rest-1,i+2,j-1);
        int p8 = jump(x,y,rest-1,i+2,j+1);
        return p1+p2+p3+p4+p5+p6+p7+p8;
    }

    int ways2(int x,int y,int rest){
        vector<vector<vector<int>>>dp(10,vector<vector<int>>(9,vector<int>(rest+1)));
        dp[x][y][0]=1;
        for(int k=1;k<=rest;k++){
            for(int i=0;i<10;i++){
                for(int j=0;j<9;j++){
                    int p1 = pick(k-1,i-1,j+2,dp);
                    int p2 = pick(k-1,i+1,j+2,dp);
                    int p3 = pick(k-1,i-2,j-1,dp);
                    int p4 = pick(k-1,i-2,j+1,dp);
                    int p5 = pick(k-1,i-1,j-2,dp);
                    int p6 = pick(k-1,i+1,j-2,dp);
                    int p7 = pick(k-1,i+2,j-1,dp);
                    int p8 = pick(k-1,i+2,j+1,dp);
                    dp[i][j][k] = p1+p2+p3+p4+p5+p6+p7+p8;
                }
            }
        }
        return dp[0][0][rest];
    }
    int pick(int k,int i,int j,vector<vector<vector<int>>>&dp){
        if(i>9||j>8||i<0||j<0){
            return 0;
        }
        return dp[i][j][k];
    }
};
int main(){
    Solution a;
    int k = 10;
    int x = 7;
    int y = 7;
    int num = a.ways(x,y,0,0,k);
    cout<<"num1:"<<num<<endl;
    int num1 = a.ways2(x,y,k);
    cout<<"num2:"<<num1<<endl;
}